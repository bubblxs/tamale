#include <iostream>
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

std::vector<std::string> read_appids(const std::string &file_path)
{
    std::ifstream file(file_path);

    if (!file)
    {
        std::cerr << "appids file cannot be opened" << std::endl;
        exit(1);
    }

    std::string appid;
    std::vector<std::string> appids;

    while (std::getline(file, appid))
    {
        appids.push_back(std::move(appid));
    }

    file.close();

    return appids;
}

// tryna get a bimmer, e46
void tamale(const std::string &appid)
{
    std::stringstream appid_path;
    appid_path << TMP_DIR_PATH << PATH_SEPARATOR << "steam_appid.txt";

    std::ofstream file(appid_path.str().c_str(), std::ios::binary);

    if (!file)
    {
        std::cerr << "file 'steam_appid.txt' cannot be created" << std::endl;
        exit(1);
    }

    file << appid;
    file.close();

    SteamAPI_Init();

    std::remove(appid_path.str().c_str());

    std::this_thread::sleep_for(std::chrono::minutes(30));

    SteamAPI_Shutdown();
}

int main(void)
{
    std::vector<std::string> appids = read_appids(APPIDS_FILE_PATH);

    while (true)
    {
        std::vector<pid_t> pids;

        for (const std::string &appid : appids)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(666));

            pid_t pid = fork();

            if (pid < 0)
            {
                std::cerr << "foik failed" << std::endl;
                exit(1);
            }
            else if (pid == 0)
            {
                tamale(appid);
                exit(0);
            }
            else
            {
                pids.push_back(std::move(pid));
            }
        }

        for (const pid_t &pid : pids)
        {
            waitpid(pid, nullptr, 0);
        }
    }

    return 0;
}