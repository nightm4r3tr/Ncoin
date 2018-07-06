
BUILD ON LINUX
-----------
Install the dependencies required to build Ncoin:
```
sudo apt-get install build-essential libssl-dev libboost-all-dev libqrencode-dev pkg-config libminiupnpc-dev qt5-default qttools5-dev-tools libgmp3-dev autoconf automake libtool

sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev
```
Execute the following commands in the Terminal to install Ncoin:
1. `git clone https://github.com/ncoindev/ncoin`

2. `cd ncoin`

3. To compile the headless daemon (ncoind), enter the following:
    * `cd src`

    * `make -f makefile.unix`

    * `strip ncoind`

    * `sudo cp ncoind /usr/local/bin`

4. To build the graphical wallet (Ncoin-qt), enter the following:
    * `qmake`
    
    * `make`
    
    * `strip Ncoin-qt`
    
    * `sudo cp Ncoin-qt /usr/local/bin`

For more information please visit the website:

https://www.ncoincoin.com
