# Friday Night Funkin' - JTC^2 Mod

This is the repository for [Friday Night Funkin': Vs. JTC^2](https://gamebanana.com/wips/53244).

**A fork of the Friday Night Funkin' legacy repo.**

https://github.com/user-attachments/assets/77e0e167-ac4a-4baf-9e92-689a0220b6b9


## Main Developers:
![jtc_dev_team](https://user-images.githubusercontent.com/58647349/173499193-ae4abb15-6879-40b1-b87a-d34a324a28ad.png)
- [Suki](https://www.youtube.com/channel/UCMI12jyPsfv8ncm5VjD8h5w) - Main Playtester
- [FrogTreat](https://oliwiadeyna.wixsite.com/frogtreat) - Director, Animator, Artist and Charter
- [Dificuz](https://www.youtube.com/channel/UCTJR8HpFUTUgyg7scqH7wIw) - Artist, Charter, and Programmer
- [Feeshy](https://twitter.com/JustFeeshy) - Lead Programmer (Sorry for the crappy outdated code)
- [Varsavi](https://www.instagram.com/varsavi_official/) - Lead Song Composer
- [JDST](https://www.youtube.com/@JDST) - Song Composer and Joul's Soundfont

## Special Thanks:
- [Duckint](https://github.com/Duckint) - Grammar Corrections
- [Sylvefloat](https://github.com/Sylvefloat) - Note Splash Animation
- [PolybiusProxy](https://github.com/polybiusproxy) - VLC Extenstion
- [Cracsthor](https://gamebanana.com/members/1844732) - PhantomMuff Font

## Building

This repo now uses HMM through [hmm.json](/hmm.json) for most Haxe dependencies, so you do not need to manually install every library one by one anymore.

### Prerequisites

1. Install [Haxe 4](https://haxe.org/download/version).
2. Install HMM:

```sh
haxelib install hmm
```

3. Clone the repo with submodules, or initialize them after cloning:

```sh
git clone --recurse-submodules <repo-url>
cd JTC-2
git submodule update --init --recursive
```

### Install dependencies

Run HMM from the project root:

```sh
haxelib run hmm install
```

If `discord_rpc` is missing on your machine, install it manually:

```sh
haxelib git discord_rpc https://github.com/Aidan63/linc_discord-rpc
```

### Build the mod

For the current macOS debug workflow used in this repo:

```sh
haxe export/debug/macos/haxe/debug.hxml
```

That produces the app bundle at:

```txt
export/debug/macos/bin/Joul The Cool.app
```

### Run on macOS

After building, use the helper script:

```sh
./run_jtc_mac.sh
```

This script:

- replaces the bundled `mod_assets` folder with your current local `mod_assets`
- opens the built `.app`

That is the recommended way to test changes locally on macOS, since the mod assets live outside the compiled source and need to be copied into the app bundle.

### Notes

- Main dependency versions are pinned in [hmm.json](/hmm.json).
- The project classpaths live in [Project.xml](/Project.xml), including `build`, `mod_source`, and `linc_luajit`.
- If you update submodules or dependency versions, rerun `haxelib run hmm install` before rebuilding.
