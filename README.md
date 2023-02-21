Hcrack is an open source password cracker.
You can install it with:
```
git clone https://github.com/Br0k3r6/hcrack.git
cd hcrack/
```
These are the next steps for different Linux distros:

Debian:
```
sudo apt update
sudo apt install python3
sudo apt install gcc g++
```
Arch Linux:
```
sudo pacman -Sy
sudo pacman -S python3
sudo pacman -S gcc g++
```

The last command that you have to run works on both system distros:
```
sudo make
```
or
```
sudo bash build.sh
```
