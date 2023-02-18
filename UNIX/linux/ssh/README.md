I am very comfortable using ssh.

I have learnt to ssh between hosts on my own network and how to enable port
forwarding so I can connnect outside of my network.

I know that a file is generated in ~/.ssh/known_hosts which keeps track of
servers you have connected to and trust. And that this file is used to prevent
man in the middle attacks.

I have configured my laptops to easily connect to each other by setting up the
~/.ssh/config. I also ensured to not use the default port 22 for an added layer
of security. To allow this I needed to also configure the file in
/etc/ssh/sshd_config to the non-default port.

I hardened my machines my disabling ssh password authentication and only
allowing ssh using ssh-keys.
I have done this on Linux, MacOS, and Windows 10.
