
BUILD ON LINUX
-----------
Install the dependencies required to build Baxur:
```
sudo apt-get install build-essential libssl-dev libboost-all-dev libqrencode-dev pkg-config libminiupnpc-dev qt5-default qttools5-dev-tools libgmp3-dev autoconf automake libtool

sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev
```
Execute the following commands in the Terminal to install Baxur:
1. `git clone https://github.com/baxurdev/baxur`

2. `cd baxur`

3. To compile the headless daemon (baxurd), enter the following:
    * `cd src`

    * `make -f makefile.unix`

    * `strip baxurd`

    * `sudo cp baxurd /usr/local/bin`

4. To build the graphical wallet (Baxur-qt), enter the following:
    * `qmake`
    
    * `make`
    
    * `strip Baxur-qt`
    
    * `sudo cp Baxur-qt /usr/local/bin`

For more information please visit the website:

https://www.baxurcoin.com
