---
title: OSI模型与TCP/IP模型分析
categories: Introduction to OSI/RM and TCP/IP 
tags: 计算机网络
toc: true
abbrlink: d4827b8
date: 2020-06-02 22:55:29
---





本文旨在分析OSI模型和TCP/IP模型在分层结构上的差异以及各层之间实现协议与功能上的区别进行阐述<br>
## OSI/RM (Open System Internetwork Reference Model)
## TCP/IP 
 <!-- more -->
OSI参考模型是一个具有七层结构的体系模型，由国际标准化组织（ISO）提出，目的旨在建立一个全世界都遵循的统一标准，但由于其过于理想化，力求完美的理想状态，导致了OSI参考模型的软件效率极低。目前的流行的协议栈是TCP/IP，但是由于OSI七层结构有很大的贡献（精确定义了软件工程内的三大概念：服务，协议，接口），所以OSI参考模型具备很好的学习意义。<br>
<p align="center">本文以自底向上的方式来介绍OSI/RM</p>

### 物理层
物理层是OSI参考模型中的最底层，主要定义了系统的电气、机械、过程和功能标准。如：电压、物理数据速率、最大传输距离、物理联接器和其他的类似特性。物理层的主要功能是利用传输介质为数据链路层提供物理联接，负责数据流的物理传输工作。物理层传输的基本单位是比特流，即0和1，也就是最基本的电信号或光信号，是最基本的物理传输特征（来自百度百科）<br>
物理层的主要功能是：利用传输介质为数据链路层提供物理连接，实现比特流的透明传输。
物理层的作用是实现相邻计算机节点之间比特流的透明传送，尽可能屏蔽掉具体传输介质和物理设备的差异。使其上面的数据链路层不必考虑网络的具体传输介质是什么。“透明传送比特流”表示经实际电路传送后的比特流没有发生变化，对传送的比特流来说，这个电路好像是看不见的。

### 数据链路层
数据链路层主要功能有：
1. 成帧 ：数据链路层的传输单位是帧（Frame），任务时将来自于网络层出来的ip数据报（packet）组装成帧。
2. 差错控制 ： 通过各种控制协议，将有差错的物理信道变为无差错的、能可靠传输数据帧的数据链路。（如信号干扰等导致的比特位变化） 无纠错功能，检测到错误直接丢弃
3. 流量控制 ： 传输速度不一致（发送方和接收方的速度不匹配） 通过流量控制协调发送速率。
4. 传输管理 ：  暂无

### 网络层
<p align="center">OSI/RM 中最复杂的一层，提供的功能最多 </p>

网络层主要功能有 ：
1. 成数据报 ： 网络层的传输单位是数据包（packet），一样接受上层的segment并且封装成数据报（加上ip信息等控制信息）
2. 流量控制 ： 数据链路层的功能冗余，与数据链路层的流量控制一直。
3. 拥塞控制 ： 缓解由于大量丢失分组情况的发生，主动降低发送速率。（建设良好网络环境的基础！）
4. 差错控制 ： 通信两节点之间约定的特定检错功能。网络层的差错控制具有纠错能力，如奇偶校验码。
5. 路由控制 ： 网络层最重要的功能，控制路由转发，根据路由协议来选择路线转发数据包。

> 网络层是通信子网的最高层，在下两层的基础上向资源子网提供服务。一般地，数据链路层是解决同一网络内节点之间的通信，而网络层主要解决不同子网间的通信。与数据链路层流量控制不同的是，前者控制的是网络相邻节点间的流量，后者控制的是从源节点到目的节点间的流量。其目的在于防止阻塞，并进行差错检测。

### 传输层 
OSI的上三层的主要任务是数据通信，上三层是数据处理，其中传输层（Transport Layer）是OSI的第四层，是通信子网和资源子网的接口和桥梁，起到了承上启下的作用。功能主要是为端到端提供可靠的传输服务，为端到端连接提供流量控制，差错控制，服务质量，数据传输管理等服务。


### 会话层
会话层允许不同主机的各个进程之间进行会话。会话层利用传输层提供的端到端的服务向表示层提供它的增值服务。服务主要为表示层实体或用户进程建立连接并在连接上有序地传输数据，这就是会话，也称建立同步（SYN）<br>
用户可以按照半双工、单工和全双工的方式建立会话。当建立会话时，用户必须提供他们想要连接的远程地址。而这些地址与MAC（介质访问控制子层）地址或网络层的逻辑地址不同，它们是为用户专门设计的，更便于用户记忆。域名（DN）就是一种网络上使用的远程地址例如 ： www.3721.com就是一个域名。

### 表示层
表示层是OSI/RM的第六层，它对来自应用层的数据和命令进行解释（也即对应用层提供服务！）
对各种语法赋予相应的含义，并按照一定的格式传给会话层。<br>
主要功能 ： 编码、数据格式转换和加密解密,压缩与解压缩。

### 应用层
应用层（Application Layer）是OSI参考模型的最高层，它是计算机用户，以及各种应用程序和网络之间的接口，其功能是直接向用户提供服务，完成用户希望在网络上完成的各种工作。它在其他6层工作的基础上，负责完成网络中应用程序与网络操作系统之间的联系，建立与结束使用者之间的联系，并完成网络用户提出的各种网络服务及应用所需的监督、管理和服务等各种协议。此外，该层还负责协调各个应用程序间的工作。
<br>
主流的应用层协议有： HTTP(HyperText Transfer Protocol，SMTP，TELNET，FTP(File Transport Protocol)

## Conclusion 
OSI/RM 是一种理想中的模型，在互联网尚未形成时就已经被提出，所以OSI模型具有很好的理论意义，但是在实践方面却远不如TCP/IP协议来的适应，因为TCP/IP协议本身就是在互联网的基础上被提出，所以与实践有很强的联系性！

## TCP/IP 被组织成四层结构
ARPA在研究ARPAnet 时提出的TCP/IP模型，模型由低到高 依次为网络接口层（OSI的物理层和数据链路层），网际层，传输层和应用层（OSI的会话层，表示层，应用层）。TCP/IP被广泛应用，成为事实上的国际标准。<br>
以下是TCP/IP分层模型
        ┌────------────┐┌─┬─┬─-┬─┬─-┬─┬─-┬─┬─-┬─┬─-┐
　　│　　　　　　　　││Ｄ│Ｆ│Ｗ│Ｆ│Ｈ│Ｇ│Ｔ│Ｉ│Ｓ│Ｕ│　│
　　│　　　　　　　　││Ｎ│Ｉ│Ｈ│Ｔ│Ｔ│Ｏ│Ｅ│Ｒ│Ｍ│Ｓ│其│
　　│第四层，应用层　││Ｓ│Ｎ│Ｏ│Ｐ│Ｔ│Ｐ│Ｌ│Ｃ│Ｔ│Ｅ│　│
　　│　　　　　　　　││　│Ｇ│Ｉ│　│Ｐ│Ｈ│Ｎ│　│Ｐ│Ｎ│　│
　　│　　　　　　　　││　│Ｅ│Ｓ│　│　│Ｅ│Ｅ│　│　│Ｅ│它│
　　│　　　　　　　　││　│Ｒ│　│　│　│Ｒ│Ｔ│　│　│Ｔ│　│
　　└───────------─┘└─┴─┴─-┴─┴─-┴─┴─-┴─┴─-┴─┴-─┘
　　┌───────-----─┐┌─────────-------┬──--------─────────┐
　　│第三层，传输层　││　　　ＴＣＰ　　　│　　　　ＵＤＰ　　　　│
　　└───────-----─┘└────────-------─┴──────────--------─┘
　　┌───────-----─┐┌───----──┬───---─┬────────-------──┐
　　│　　　　　　　　││　　　　│ＩＣＭＰ│　　　　　　　　　　│
　　│第二层，网间层　││　　　　└──---──┘　　　　　　　　　　│
　　│　　　　　　　　││　　　　  ＩＰ　　　　　　　　　　　 │
　　└────────-----┘└────────────────────-------------─-┘
　　┌────────-----┐┌─────────-------┬──────--------─────┐
　　│第一层，网络接口││ＡＲＰ／ＲＡＲＰ　│　　　　其它　　 　│
　　└────────------┘└─────────------┴─────--------──────┘
　　　　　　 TCP/IP四层参考模型

### 网络接口层
TCP/IP协议的网络接口层 表示与物理网络的接口，但实际上TCP/IP并未真正描述这一部分，只是指出主机必须使用某种协议与网络相连，以便在其提供的服务上传递IP分组（TCP/IP标准并不定义与ISO数据链路层和物理层相对应的功能）。具体的物理局域网可以是： 以太网，令牌环网，电话网等。

### 网际层（网间层，网络层）
对应于OSI七层参考模型的网络层。本层包含IP协议、RIP协议(Routing Information Protocol，路由信息协议)，负责数据的包装、寻址和路由。同时还包含网间控制报文协议(Internet Control Message Protocol,ICMP)用来提供网络诊断信息。

### 传输层
TCP/IP协议的传输层提供两个具体的协议，一个是面向连接的TCP，一个是无连接的UDP


### 应用层
与OSI/RM的一致，不做过多阐述。


## TCP/IP模型与OSI模型的区别与联系
1. OSI引入了服务、接口、协议、分层的概念（这一点很关键！符合软件工程的设计思想），TCP/IP借鉴了OSI的这些概念建立TCP/IP模型。OSI先有模型，后有协议，先有标准，后进行实践；而TCP/IP则相反，先有协议和应用再提出了模型，且是参照的OSI模型。OSI是一种理论下的模型，而TCP/IP已被广泛使用，成为网络互联事实上的标准。

2. OSI/RM 模型具有良好的通用性，没有偏向于任何特定的协议。

3.  OSI模型的网络层同时支持无连接和面向连接的通信，但是传输层只支持面向连接的通信；TCP/IP模型在网络层只支持一种模式（无连接），但是在传输层同时支持两种通信模式。


# 参考资料：
https://blog.csdn.net/yaopeng_2005/article/details/7064869
《王道考研计算机网络》》