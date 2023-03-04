# Todo-cli

This is a cli app that will probably only work on linux.

## Download it:
Check the releases page.


## Compile it yourself:
It requires you to have Boost installed as it cant build it from source.

### Boost:

Arch:
```bash
~# pacman -S boost
```

Ubuntu (untested):
```bash
~# add-apt-repository ppa:boost-latest/ppa
~# apt-get update
~# apt-get install libboost-all-dev
```

### Installation:

```bash
git clone https://github.com/omoNattie/cli-todo
cd cli-todo

mkdir build/
cmake -S . -B build/
cd build/
make
```

### Create the database:
```bash
cd build/
mkdir data/
touch todo_db.db
```

# Now that you've installed it, you need to add it to your system's PATH.


```bash
# ./bashrc

export PATH="path/to/todo/build:$PATH"
```
Zsh should work the same way.

```bash
# ~/.config/fish/config.fish

fish_add_path -m path/to/todo/build
```