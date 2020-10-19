---
title: specific details about IPv4
tags: 计算机网络
abbrlink: 8e598b23
date: 2020-06-22 21:14:52
---

### IPv4 (Internet Protocol version 4)
 <!-- more -->
##### IPv4 分组格式(packet format)
一个典型的ip分组由首部和数据两部分组成。首部的前20B是固定值，所有的ip分组都统一拥有。在首部固定部分后面是一些可选字段，其长度可变，用来提供错误检测以及安全机制。
![20200923193420](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20200923193420.png)
##### IPv4分组参数详解
1. 版本 占4bits，目前广泛使用的版本号是4
2. 首部长度 占4bits，单位是4B 标明首部的总长度，因为可选字段的缘故所以首部的总长度是可变的，比如首部长度为1111，意味着整个首部的长度是4B*15=60B，也就是说首部最大的总长度就是60B。
3. 总长度 占16bits ，单位是1B 这里的总长度指的是包括首部和数据部分的总长度，最大值是 2^16-1 =65535B,但是以太网帧MTU的最大值是1500B，因此当一个ip数据报封装成帧时，数据报的总长度不能大于下面数据链路层的MTU的值。
4. 标识 占16bits 起到一个计数器的作用，每生成一个ip分组就++1，用来标识属于同一个分组的小分组（分片之后），以便目的主机能够正确的重装成原来的数据报。
5. 标志 占3bits 标志字段的最低位是MF，MF=1表示后面还有分片，MF=0表示为最后一个分片，标识字段中间位是DF，只有当DF=0 时才允许分片。（只有后2bit才有意义）
6. 片偏移 占13bits 指的是较长的分组在分片后，对应的某一片在原分组的相对位置，片偏移以8B为单位，即每个分片的长度一定是8B的整数倍。
7. 首部校验和 只校验分组的首部
8. 生存时间(Time To Live TTL) TTL减为0后，会被路由丢弃。
9. 协议 占8bits， 指上层传输层的协议， 当值为6时代表的是 TCP，值为17代表 UDP <br>
10-11. 源地址字段 占4B 目的地址字段占4B

#### IP 地址详解 
ip地址={<网络号>,<主机号>}
传统分类： 
1. A类地址 ： 网络号占8bits，主机号占24bits ，其中1\~126 归属A类地址，可用网络数为2^7-2 减去的2分别为127开头的环回地址和全0的保留地址。
2. B类地址 ： 网络号占16bits，主机号占16bits，其中128\~
191归属B类地址，可用网络数为2^14 -1 只需要减去全0的保留地址。
3. C类地址 ： 网络号占24bits，主机号占8bits，可用网络数为2^21-1,其中192\~223归属C类地址，减去的1 是全0地址。
4. D类地址 ： 多播地址 224\~239
5. E类地址 ： 240\~255 保留使用

##### 子网划分 （解决A-E类地址利用低的方法）
向主机位借位划分子网，增加子网位，形成三级ip地址，也即ip地址={<网络号>,<子网号>,<主机号>}，实则只是对内部网络的划分，对外表示仍然是没有划分子网的网络。
因为子网划分的存在，需要用子网掩码来表达原网络对主机号的借位。
>子网掩码：网络位，子网位全为1的ip地址，被路由选择中广泛利用，常用于与ip地址进行与运算，判断该地址是否属于本网段。

#### CIDR 无分类域间路由选择
CIDR 就是在变长子网掩码的基础上提的一种消除传统A，B，C网络划分，并且支持超网构建的ip地址划分方法。 CIDR大幅度提高了ip地址的空间利用率，减小路由表大小，提高路由转发能力。
CIDR主要特点：
(1). 消除了传统ip划分以及划分子网的概念，更有效的分配ipv4地址，CIDR使用“网络前缀”的概念代替子网络的概念， ip地址={<网络前缀>,<主机号>}
CIDR记法： ip地址/网络前缀所占比特数 例如 183.30.182.185/24  表示网络前缀为15，可以看出子网掩码为255.255.255.0
(2). 将网络前缀都相同的连续ip地址组成“CIDR地址块”，地址的聚合称为路由聚合，有效减少路由器之间的路由交换，提高网络性能。CIDR采用最长前缀匹配。




### NAT (Network Address Translation)
NAT指的是将专用网络地址(intranet)转换为共用地址(internet)，从而对外隐藏内部管理的ip地址，NAT大大节省了ip地址的消耗，同时降低了内部网络受到攻击的风险。
为了网络安全 ，有专门划分出来的ip地址为私有ip地址。私有ip地址只用于LAN，不用于WAN连接（私有地址不能直接连接Internet，需要通过网关进行NAT转换之后才能链接外部Internet。）私有网段如下：
> A类地址：1 个A类网段 10.0.0.0 ~ 10.255.255.255
B类地址： 16个B类网段 172.16.0.0 ~ 172.31.255.255
C类地址： 256个C类网段 192.168.0.0 ~ 192.168.255.255

一般路由器都维护着一个NAT转换表 存放着{本地ip地址：端口}->{公网ip：端口}的字段值，将来自私有ip的请求转换成公网ip，也称为端口映射。