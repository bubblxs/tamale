<h2 align="center">tamale</h2>

> tamale is a simple - _mediocre_ - app for gnu/linux distros to farm your beloved steam cards.

> [!NOTE]  
> you might want to [check the steamworks sdk docs](https://partner.steamgames.com/doc/sdk).

download the build

- [linux 64]()

### installation and usage

> [!NOTE]  
> if you downloaded the compiled build, you can ignore the 3rd and 4th step.

- [download the steamworks sdk](https://partner.steamgames.com/downloads/list);
- extract the downloaded steamworks sdk archive;
- copy the `steam` folder from the extracted sdk to your project directory;
- copy the `steam_api.lib` file to the root of your project folder;
- copy the `libsteam_api.so` file to the shared library directory of your os;
```bash
$ sudo cp ~/Downloads/steamworks_sdk_161/sdk/redistributable_bin/linux64/libsteam_api.so /lib/x86_64-linux-gnu/
```
- build the project

```bash
$ ./build.sh
```

at this point your project should look like this: 
```
tamale/
├── steam/
├── build.sh
├── ids.txt
├── README.md
├── steam_api.lib
└── tamale.cpp
```

#### apps to farm

now, place the appids of all the games that you want to farm into ``ids.txt``. and yes. ALL. OF. THEM. - you might want to check [ArchiSteamFarm](https://github.com/JustArchiNET/ArchiSteamFarm) - one appid per line.

#### running it

open the steam and run the build

```bash
$ ./tamale.1
```
