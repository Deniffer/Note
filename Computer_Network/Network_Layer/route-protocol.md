---
title: route-protocol
tags: 计算机网络
abbrlink: e8b91f34
date: 2020-06-23 17:06:44
---

>自治系统(Autonomous System AS) : 单一技术管理下的一组路由器，利用AS内部的路由选择协议和共同的度量来确定分组在该AS内的路由，同时还使用AS之间的路由选择协议来确定分组之间的路由。
 
 <!-- more -->
### 域内路由与域间路由

1. 内部网关协议 （Interior Gateway Protocol，IGP）
在一个AS内的路由选择协议，如RIP和OSPF
2. 外部网关协议 （External Gateway Protocol, EGP）
不同AS之间的路由选择协议，目前最流行的是BGP-4

#### 路由信息协议（Routing Information Protocol RIP）
RIP是一种分布式的基于距离向量的路由选择协议，工作在应用层，使用UDP传送数据（端口520）
RIP规定：
(1). 网络中每个路由器都要维护从它自身到其他每个目的网络的距离记录（称为距离向量）<br>
(2). 距离也称跳数（Hop Count），规定从一个路由器到直接连接网络的距离为1.每经过一个路由器跳数+1
(3). RIP认为好的路径就是跳数小的路径
(4). RIP允许一条路径最多包括15个路由器（最多允许15跳），当距离=16时，表示网络不可达。可见RIP只适用于小型互联网
(5). RIP默认在任意两个使用RIP的路由器之间，每30秒广播一次RIP路由更新信息，一边自动建立并维护路由表
(6). RIP中不支持子网掩码的RIP广播，所以RIP中每个网络的子网掩码必须相同，但在RIP2中，支持变长子网掩码和CIDR。

##### 距离向量算法
每个路由表都有三个关键数据：<目的网络N,距离d,下一跳路由X>。对于每个相邻路由器发送过来的RIP报文，执行如下步骤：
(1). 对地址为X的相邻路由器发来的RIP报文，修改此报文中的所有项目：把“下一跳”的字段中的地址都改为X，并把距离字段加1
(2). 对修改后的RIP报文中的每个项目执行如下步骤：
1. 当原来路由表中没有目标网络N时，把该项目添加进路由表中。
2. 当原来路由表中有目的网络N时，且下一跳的地址是X，用收到的项目替换掉原路由表的项目。
3. 当原来路由表有目的网络N，且下一跳地址不是X，如果收到的项目的距离d小于路由表的距离，则更新。
4. 如果 180s后还没有收到相邻路由器的更新路由表，那么把该路由器的距离设为16表示为不可达。

#### OSPF(Open Shortest Path First)开放最短路径优先
OSPF协议使用分布式链路状态路由算法的典型代表，OSPF与RIP的主要区别有
1. OSPF向本自治AS中所有路由器发送信息，使用洪泛法，而RIP仅向自己相邻的几个路由器发送信息 。
2. 发送的信息是与本路由器相邻的所有路由器的链路状态，但这只是路由器知道的部分信息。而RIP中发送本路由器的所知道的全部信息，即整个路由表。
3. 只有当链路状态发生变化时，路由器才用洪泛法向所有路由器发送此消息，并且更新过程收敛的快。在RIP中，不管网络拓扑是否发生变化，路由器之间都会发生路由交换。
4. OSPF是网络层协议，直接使用IP数据报传输。
5. OSPF可以多路径间进行负载平衡， 且OSPF路由器之间交换的分组都具有鉴别功能，因而保证了仅在可信赖的路由器之间交换链路状态信息。

##### OSPF的五种分组类型
1. 问候分组，用来发现和维持邻站的可达性
2. 数据库描述分组，向邻站给出自己的链路状态数据库中的所有链路状态项目的摘要信息。
3. 链路状态请求分组， 向对方请求发送某些链路状态的详细信息。
4. 链路状态更新分组， 用洪泛法对全网更新链路状态。
5. 链路状态确认分组， 对链路更新分组的确认。

[OSPF详解](https://wenku.baidu.com/view/b4eb75ed19e8b8f67c1cb971.html)

#### 边界网关协议（Border Gateway Protocol ，BGP）
