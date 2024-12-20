#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "steam/steam_api.h"

#define TMP_DIR_PATH "."
#define PATH_SEPARATOR std::filesystem::path::preferred_separator
#define APPIDS_FILE_PATH "ids.txt"

// tryna get a bimmer, e46
void tamale(const std::string &app_id)
{
    std::stringstream appid_path;
    appid_path << TMP_DIR_PATH << PATH_SEPARATOR << "steam_appid.txt";

    std::ofstream file(appid_path.str().c_str(), std::ios::binary);

    if (!file)
    {
        perror("file 'steam_appid.txt' cannot be created");
        exit(1);
    }

    file << app_id;
    file.close();

    SteamAPI_Init();

    std::remove(appid_path.str().c_str());

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::ifstream file(APPIDS_FILE_PATH);

    if (!file)
    {
        std::cerr << "error opening " << APPIDS_FILE_PATH << " file" << std::endl;
        exit(1);
    }

    std::string app_id;
    std::vector<pid_t> pids;

    while (std::getline(file, app_id))
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        pid_t pid = fork();

        if (pid < 0)
        {
            std::cerr << "foik failed" << std::endl;
            exit(1);
        }
        else if (pid == 0)
        {
            tamale(app_id);
            exit(0);
        }
        else
        {
            pids.push_back(pid);
        }
    }

    for (pid_t pid : pids)
    {
        waitpid(pid, nullptr, 0);
    }

    return 0;
}