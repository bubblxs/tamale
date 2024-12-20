<h2 align="center">tamale</h2>

> tamale is a simple - _mediocre_ - app for gnu/linux distros to farms your beloved steam cards.

> [!NOTE]  
> if you downloaded the compiled build, you can ignore the 2nd and 3rd step.

> [!NOTE]  
> you might want to [check the steamworks sdk docs](https://partner.steamgames.com/doc/sdk).

#### compiled build

- [linux 64]()

### usage
#### download the steamworks sdk

- [download the steamworks sdk](https://partner.steamgames.com/downloads/list).

#### extract the sdk

- extract the downloaded steamworks SDK archive;
- copy the `steam` folder from the extracted SDK to your project directory.

#### copy the steam api lib

- copy the `steam_api.lib` file to the root of your project folder.

#### install the shared library

- copy the `libsteam_api.so` file to the shared library directory of your operating system. You can do this using the following command:

```bash
$ sudo cp ~/Downloads/steamworks_sdk_161/sdk/redistributable_bin/linux64/libsteam_api.so /lib/x86_64-linux-gnu/
```

#### your dir should look like this: 

```
tamale/
├── steam/
├── build.sh
├── README.md
├── steam_api.lib
└── tamale.cpp
```
#### build the project

```bash
$ ./build.sh
```

#### appids to farm

now, place the appids of all the games that you want to farm into ``ids.txt``. and yes. ALL. OF. THEM. - you might want to check [ArchiSteamFarm](https://github.com/JustArchiNET/ArchiSteamFarm) - each one per line.

```
tamale/
...
├── ids.txt
...
```

#### run it

open the Steam and run it

```bash
$ ./tamale.1
```