#!/bin/bash



sudo useradd -m KOKO
sudo groupadd Rizk
sudo useradd -G Rizk KOKO
sudo cat /etc/passwd
sudo cat /etc/group
