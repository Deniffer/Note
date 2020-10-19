---
abbrlink: '0'
---
# Data Link Layer Q&A

## Questions

#### Q1.数据链路层向网络层提供的服务(三种),适用场景
#### Q2.什么是透明传输
#### Q3.数据链路层/传输层流量控制的对象
#### Q4.信道噪声所造成的错误形式以及解决方案
#### Q5.为什么要组帧/组帧需要解决什么问题
#### Q6.CRC计算过程/预算规则/FCS是什么
#### Q7.奇偶校验码的缺陷
#### Q8.海明码是什么/计算过程/检错和纠错能力
#### Q9.什么是捎带确认
#### Q10.什么是连续ARQ协议
#### Q11. GBN与SR协议之间的区别/优劣
#### Q12. GBN/SR协议的接收窗口/发送窗口应满足什么条件/为什么？
#### Q13. 什么是信道吞吐率/信道利用率
#### Q14. 信道的三种状态
#### Q15. 各种动态划分协议的使用范围/相应例子
#### Q15. 什么二进制退避算法/限制
#### Q16. 为什么传播延迟接近0时，CSMA/CD的信道利用率趋近100%        
#### Q17. 计算最短帧长需要注意的问题/为什么要最短帧长
#### Q18. CDMA计算方法
#### Q19. 局域网的三要素
#### Q20. 如何理解ppp协议/HDLC协议
#### Q21. 网桥的优缺点/基本特点






## Answer

Q1. 什么样的比特组合都应当能在链路上进行传输。
Q2.  数据链路层主要将物理层提供的可能出错的物理连接改造成逻辑上无差错的数据链路，并向上层网络层提供服务。
-   无确认无连接的服务：目的机器收到数据帧时不用发回确认，对于丢失的帧，数据链路层不负责重发而交由上层处理。适用于以太网这种误码率较低的通信信道或实时通信。
-   有确认无连接的服务：不需要提前建立链路连接，但目的机器收到数据帧时必须发回确认，若发送方在规定时间内没收到确认帧则重传该数据帧。适用于无线通信等误码率较高的通信信道。
-   有确认有连接的无符： 帧的传输分为三阶段：建立数据链路，传输帧，释放数据链路。目的机器收到数据帧之后要发回确认，该服务可靠性最高。适用于对通信要求较高的场合。

Q3. 对于数据链路层，流量控制控制的是相邻两节点之间数据链路上的流量；而对于传输层来说，控制的则是从源端到目的端之间的流量。

Q4.由于信道噪声所造成的差错分为两种：位错和帧错。
-  位错：指帧中的某些位出现了差错。通过循环冗余校验(Cyclic Redundancy Check,CRC)可发现。
    - CRC： 通过自动重传请求(Automatic Repeat reQuest,ARQ)方式来重传出错的帧。具体是让发送方将要发送的数据帧附加一定的CRC冗余检错码一并发送。
-   帧错：指帧的丢失、重复、失序等错误。可引入定时器和编号机制，确保每一帧能够正确交付给目的节点。

Q5.组帧能够提高数据传输效率(只需将一定位数的bits组成一个帧，出错时只重发出错的帧)，其次，为了能让接收方正确地接受并检查所传输的帧，双方必须按照一定的规则来组帧(体现在协议一致)。组帧需要解决帧定界、帧同步、透明传输等问题。所以有常见的四种组帧方法。
-   字符记数法(面向字节)：在帧头部使用一个计数字段标明帧内字符数，缺点：一旦标明字段出错就失去同步的效果。
-   字符填充的首尾定界法：采用一些特殊字符来界定开始和结束，为了实现透明传输，一旦信息部分出现特殊字符则需要做转义处理。
-   零比特填充的首尾标志法(面向比特)：使用特定的比特序列来界定开始和结束。如HDLC协议中的01111110，一旦信息部分出现连续的六个1，则向第六个1前面填充一个0，使其转义(此时接收方要进行去除的过程)。优点:易于使用硬件实现，性能由于字符填充法。
-   违规编码法：局域网IEEE802标准采用改变码，原理是利用了未利用的电平对来界定开始和结束。

Q6.模2除法(同0异1)，不进位不借位，仔细请做例题体会，除数是多项式，被除数是m+r位(其中r为多项式的项数，计算时用0填充)。FCS是帧检验序列(Frame Check Sequence)也即本例中的m+r位(被除数)。接收方收到数据后对多项式进行模2除法，若无余数则正确接收。

Q7. 只能检查出奇数位的错误，也即偶数位的错误发现不了，且无纠错能力。

Q8. 汉明码的由来：如果一条信息中包含更多用于纠错的位，且通过妥善安排这些纠错位使得不同的出错位产生不同的错误结果，那么我们就可以找出出错位了。在一个7位的信息中，单个位出错有7种可能，因此3个错误控制位就足以确定是否出错及哪一位出错了。
计算过程：
(1). 求出校验码位数k (校验码位数需满足$2^k-1\ge n+k$) (要纠正一位的错误：如纠正两位的话则需k+1位)
满足的理由如下(校验码有k位。则校验码一共有$2^k$种取值方式。其中需要一种取值方式表示数据正确，剩下$2_k-1$种取值方式表示有一位数据出错。因为编码后的二进制串有n+k位，因此k应该满足不等式)
(2). 将校验码放到2的幂次方的位置
(3). 求出校验码的值，并使其二进制所对应位的异或值和为0
![校验过程](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20200921091730.png)
> 注：海明码纠错"d"位，需要码距为2d+1的编码，检错"d"位需要码距为d+1位。

Q9.为了提高传输效率，将确认帧捎带在一个回复帧上，称为捎带确认。一般而言题目出现捎带确认则表明需要计算回复帧的传输延迟。

Q10. 当滑动窗口技术与请求重发技术结合后，由于窗口尺寸开到足够大时，帧在线路上可以连续的流动，所以称为连续ARQ协议。

Q11. [两种协议的详解](https://www.zhihu.com/question/44602610)
这两种协议都是解决流水线技术带来的问题。
-   重传 对于丢失分组 n，在GBN中，发送方会重传n及n以后的数据包；在SR中，只会重传n。
-   缓存 对于乱序达到的分组，在GBN中，接受段端会直接丢弃；在SR中，会把它们缓存下来。
-   定时器 在GBN中一个连接只会设置一个定时器，在SR中会为每个分组设置定时器。
GBN优缺点： 优点是接收方不需要缓存任何失序分组，唯一需要维护的信息就是下一个按序接收的分组的序号。缺点就是随后对该分组的重传也许会丢失或出错，进而引发更多的重传。
SR优缺点： 优点是只重发丢失的分组，降低了分组开销。

Q12.GBN协议中接收窗口=1，发送窗口=$2^k-1$;SR协议中满足接收窗口+发送窗口$\le 2^k$
原因如下:GBN协议中最多只能有$2^k$个窗口，故除去一个接受窗口外，最多只有$2^k-1$个发送窗口。SR协议中考虑发送方发送n个帧后，接收方完全接收，但确认帧全部丢失，此时，发送方重发n个帧，但接收方无法区分新旧帧($\textcolor{red} {也即旧帧看成新帧，发生差错}$)。故SR协议中不仅要满足$$接收窗口+发送窗口\le 2^k$$
而且接收窗口$W_R$不应大于发送窗口$W_T$(浪费空间无意义)。所以接收窗口不应大于序号范围的一半也即$$W_{Tmax}=W_{Rmax}=2^{(n-1)}$$


Q13. $$信道利用率=\frac{L/C}{T}$$
其中L是发送的比特数，C是数据传输率，T是发送周期
$$信道吞吐率=信道利用率*发送方发送速率$$

Q14.信道的状态分为三种：忙，空闲，碰撞。

Q15.用来解决CSMA/CD的冲突问题。首先确定基本退避时间，一般为两倍的传播时延(即争用期长短)，定义参数k为重传次数；当k大于或等于10时，k不再增长。其次，在离散的集合$[0,1,\cdots ,2^k-1]$中随机抽取一个数r，重传所需要退避的时间就是r倍的基本退避时间，也即r倍的争用期。当重传次数达16次，则说明网络过于拥挤，认为此帧永远不能正确发出，抛弃此帧并向高层报告出错。限制在于$k\le 10$

Q16. 因为CSMA/CD协议所遇到的碰撞原因是因为传播时延导致的，一般不存在传播时延或者传播时延极低的情况下，基本上不可能发生碰撞，所以信道利用率趋近100%。

Q17. 有最小帧长的原因是因为CSMA/CD中，工作模式是半双工，通信双方不能同时收发数据，会产生冲突。为了避免冲突的产生，要让传输时延要大于传播时延，一旦发送方检测到信号，则立即停止发送数据，并且用二进制退避算法等待一段时间然后再次发送数据(主要是为了能检测到冲突的发生，并且中断数据)。计算最短帧长时应时刻注意传播距离是两倍！是往返的，要考虑两倍的传播时延或者路径！

Q18. 
![20200922204329](https://deniffer-picbed.oss-cn-shenzhen.aliyuncs.com/img/20200922204329.png)


Q19. 局域网的三要素是:拓扑结构、传输介质、介质访问控制方式

Q20. 
-   网桥的处理对象是帧，所以它是工作在数据链路层那个的设备
-   网桥必须具备寻址和路径选择能力，以确定帧的传输方向
-   网桥可以在不同或相同的局域网中存储和转发帧，可以进行链路层的协议转换。
-   网桥应有足够大的缓存空间，能够使短时间帧的到达速率高于转发速率
优缺点：
优点： 
    - 能过滤通信量，可使用不同的物理层，互联不同类型的局域网，提高了可靠性
缺点：
    -  增大了时延(存储转发处理)；MAC层无流量控制功能；只适用于用户数不多和通信量不大的局域网，还会因为传播过多的广播信息导致广播风暴。

    