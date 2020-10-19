---
abbrlink: '0'
---
#### Q1.为什么TCP不提供广播/组播服务
#### Q2.TCP/UDP常用协议
#### Q3.UDP的优点/适用场景
#### Q4.Estimate-RTT计算公式
#### Q5.TCP/IP协议中封装过程
#### Q6.TCP建立过程
#### Q7.拥塞控制的算法和使用





Q1.
因为TCP是面向连接的服务，一旦用于广播/组播中，需要建立大量的TCP连接、TCP缓冲区，维护大量的TCP连接，造成计算资源的大量浪费，所以TCP一般不提供广播和组播服务。

Q2.
TCP常用于 HTTP(80) HTTPS(443) FTP(20,21 tips：两个端口一个维护连接状态，一个传输数据) SSH(22) TELNET(23) SMTP(25)   IMAP(143) POP3(110)

UDP常用于 
- SNMP(161,162):管理网络中各种基础硬件设施，比如路由器，交换机，防火墙等等。这些设备传输自己的参数，状态就通过UDP的方式.
- NTP(Network Time Protocol 123):时间服务器，他的作用就是提供标准时间，你可以用它来校准自己的电脑时间。因为你找NTP服务器真的只想知道现在是几点了，没必要很正式的来个三次握手。
- DHCP(Dynamic Host Configuration Protocol 67,68):是用来动态分配IP的。这个协议还真没法用TCP，因为一开始客户都不知道DHCP服务器在哪，跟谁握手都不知道。 DHCP是用目标地址255.255.255.255广播一条消息，请求IP，而只有DHCP服务器才会响应广播报文。
- RSTP(Real Time Streaming Protocol 554):用于流媒体传输，尽管发送的音频，视频这样大容量的文件，但因为对实时性的要求更高，所以接收方不能花时间反复确认报文无误，而且TCP最要命的是，如果收到了一大堆连续编号的报文，结果在最前面漏了一个，TCP会要求把漏的补齐后，才会把数据传到应用层去.

Q3.
- 分组开头只有8B 开销小(TCP 20B的报文头)
- 无需建立连接(省去三次握手的时间)，延迟低
- 无拥塞控制，即便在网络拥塞的情况下，发送效率也很高。
- 发送方无需维护连接状态，可以支持更多的活动客户机

Q4.
$$Estimate RTT=(1-\alpha)*(old RTT)+\alpha*(New RTT)$$

Q5.
[详细解释！！！](https://blog.csdn.net/qq_26093511/article/details/78739198)
$$MTU = MSS + TCP Header + IP Header. $$ 
- MTU(Maximum Transport Unit):网络传输最大报文包，$\textcolor{red}{以太网中的MTU规定为1500B}$ 
- MSS(maximum segment size):最大分节大小，为TCP数据包每次传输的最大数据分段大小，一般由发送端向对端TCP通知对端在每个分节中能发送的最大TCP数据。$\textcolor{red}{MSS值为MTU值减去IPv4 Header（20 Byte）和TCP header（20 Byte）得到。}$
TCP报文段首部占20B(不计算任选字段的前提下)
以太网帧
![20200927102845](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20200927102845.png)

Q6.
[TCP建立/释放/SYN攻击解释！！！](https://zhuanlan.zhihu.com/p/53374516)

Q7.
[详解各拥塞算法！总结版](https://zhuanlan.zhihu.com/p/59656144)