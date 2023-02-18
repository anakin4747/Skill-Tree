
#!/bin/bash
sudo mount /dev/sda1 /mnt/pico

sudo cp $1 /mnt/pico
sudo sync
sudo umount /mnt/pico
