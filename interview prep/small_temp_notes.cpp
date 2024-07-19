//ip address doubt
//https://www.quora.com/What-does-an-IP-address-depend-on-a-device-or-location

//https://www.quora.com/Why-do-2-devices-on-same-local-network-show-different-IPv6-addresses-when-I-Google-whats-my-IP-Shouldnt-they-show-the-routers-IPv6

//https://superuser.com/questions/1504503/ipv6-do-two-computers-connected-on-the-same-wi-fi-have-the-same-ipv6-address

//https://serverfault.com/questions/184524/switching-to-ipv6-implies-dropping-nat-is-that-a-good-thing



CN mini projects as part of course : 
https://www.quora.com/What-are-the-latest-mini-projects-on-computer-networks-to-present-in-a-college

Create a vpn
All data from a pool of laptops or from a particular connection should go from another laptop


Related
What are some good and simple networking projects that a third year undergraduate can do in the summer as a mini project?
1) Simple Chat client(P2P),Chat client with multiple participants
(Sockets ,Multi-threading)

2) Video Chat system(Look for WebRTC)

3) Chrome plugin about notifications useful to you.May be alert for CF or TC round.

4) Something similar to online text editor - collabedit or Google docs
where simultaneously 2 people can edit text .Try to integrate with it
your chat-client

5) Proxy Server

6) Tool similar to IDM ,where you could download data in batches from different sources and assemble them in correct order.

7) Code to detect congestion in network .

Most of these are standard projects and you would easily get lot of help
from WWW. All the best :)





Related
What are some good and simple networking projects that a third year undergraduate can do in the summer as a mini project?
Build something new . Don't go old school .I have a project in mind as it is the world of AI ML and IOT these days. I just got an idea.An intelligent pi based router.

Take a Raspberry pi with inbuilt wifi or a wifi dongle.
Put in a server software like apache for client web interface
Take up Python now .And start with clustering algorithms etc (refer korth for DAA and forouzan and Tannenbaum for networking,the internet is always there to help )
The goal is to accept an incoming connection from the RJ45 Ethernet port and via a dhcp server (don't make a dhcp server ,it's an overkill,just use the open source ones available ) distribute it to clients connected to wifi (use single protocol like wpa2-psk, it's more than enough)
The above step is to setup a router , you can even use ready made packages for the above

Now comes the ML and AI part …the pi must monitor the connected clients

Disconnect internet and display a page of warning to clients if they go over limit .
Develop algos that monitor the random ports as used by torrent to check if a user is excessively using torrents
Develop algos to check if a user is doing a lot of downloads and warn him accordingly
Limit speeds to users after certain thresholds , different speed limiters for different levels
Admin permission to se non standard ports
Intelligent website filtering with reports to admin
Inbuilt DNS server that uses AI to improve over time , in a way removing the DNS server latency
Static page mirroring server (why , only cloudflare can do that , no man)
The list can be endless and I know it's more than a summer project but you can develop parts of it , even many of the modules are open source available like tomato server (not sure if pi version is there , it runs on micro httpd so it most probably would run on pi as well)

Let me know if you are pulling this off , I am interested
