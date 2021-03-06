---
abbrlink: '0'
---
# Physical Layer Q&A

## Questions

#### Q1.什么是调制、编码
#### Q2.奈氏准则与香农定理的区别
#### Q3.宽带信号与基带信号的区别
#### Q4.码元、信号、信道是什么
#### Q5.模拟信号->数字信号的过程、要点
#### Q6.虚电路的优缺点
#### Q7.数字数据->数字信号的各个编码方式、差异、适用范围
#### Q8.奈氏/香农定理的使用场景
#### Q9.10BASE5的含义
#### Q10.集线器工作原理、为什么不能解决冲突域
#### Q11.为什么曼彻斯特编码所需频宽是原始基带的两倍
#### Q12.信噪比的db表示
#### Q13.比特率与信息传输速率的关键公式
#### Q14.物理层的接口特性


--- 

## Answers

Q1. 编码和调制是数据->信号的过程，数据要想进行传输就必须通过调制或者是编码，转换成模拟信号则成为调制；转换成数字信号则称为编码。

Q2. 奈氏准则主要表达了码元的传输速率是受限的(由于码间串扰的原因),否则接收端无法正确识别所携带的比特是0还是1;香农定理定义了比特率的上限值,$$Limit\ Transfer\ Rate = Wlog_{2}(1+\frac{S}{N}) $$其中$\frac{S}{N}$是信噪比,信噪比也可以表示为$10log_{10}(\frac{S}{N})$(dB)分贝单位.

Q3. 基带信号和宽带信号都是信道上传输的信号,其中
- 基带传输: 基带信号将数字0和1直接用两种不同的电压表示，然后传送到数字信道上传输($\textcolor{red}{适用于近距离传输!!!}$);
- 宽带传输: 宽带信号将基带信号进行调制后形成频分复用模拟信号,然后传送到模拟信道上传输($\textcolor{red}{适用于远距离传输!!!}$)

Q4. 
- 码元:一个固定时长的信号波形(数字脉冲)表示一位k进制数字!代表不同的离散数值的基本波形,是数字通信中的计量单位,这个市场内的信号称为k进制码元。
- 信号: 数据的电气或电磁表现,是数据在传输过程中的存在形式。
- 信道: 信号的传输媒介。一个信道可视为一条通信线路的逻辑部件;一条通信线路往往包含一条发送信道和一条接受信道。

Q5. 模拟信号->数字信号的过程称为编码,最典型的有常用于对音频信号进行编码的脉码调制(PCM:Pulse Code Modulation),其主要包括采样,量化,编码三个步骤。
1. 采样：采样的频率必须大于2倍原始信号中的最大频率,设最大频率为f,则$f_{采样}\ge 2f$,才能保证采样后的数字信号能够完整保留原来的模拟信号.
2. 量化: 采样取得的电平值按照一定的分级标准转化成对应数字(离散化)
3. 编码：将量化的结果转换为与之对应的二进制编码

Q6. 虚电路的整个通信过程分为三个阶段:
- 虚电路建立:终端系统分配一个虚电路号给该虚电路,在虚电路网络中，每个节点都维持着一张虚电路表,表中的每一项纪录了一个打开的虚电路的信息。
- 数据传输: 有序高效地传输数据，但不提供差错检验，差错检验部分交给上层处理。
- 虚电路释放： 发送“释放请求”分组，释放虚电路所占资源，逐段释放资源。
虚电路是数据报和电路交换方式的结合，集它们的优点，但是也明显存在缺点：链路的建立于拆除需要时间开销，链路的鲁棒性不够(链路中任一结点失效，整条链路失效) ，优点：是可复用的逻辑线路，分组开销相对数据包方式较小(只需包含虚电路号，无需ip等其他信息)


Q7. 数字数据编码成数字信号
- 不携带时钟信息
    - 归零编码(Return Zero):高电平代表1，低电平代表0，每个时钟周期中间均跳变到低电平(归零操作),接收方根据跳变调整时钟基准。(归零需占用一部分的带宽)
    - 非归零编码(Non Return Zero):不需要归零操作，信息密度较高,但NRZ编码无法传递时钟信号，通信双方难以同步，需自带时钟线来实现高速传输。
- 携带时钟信息
    - 反向非归零编码(Non-Return-Zero-Inverted):用信号的翻转代表0，不翻转代表1，翻转信号可视为时钟信息。被应用于USB2.0通信的编码。
    - 曼彻斯特编码(Manchester Encoding)：将一个码元分成两个相等的间隔，前高后低为1，前低后高为0。被应用于以太网10BASE5编码
    - 差分曼彻斯特编码(Differential Manchester Encoding):若码元为1，则前半个码元的电平与上一个码元的电平相同，0则相反。差分曼彻斯特码用在令牌环网中。(这两种双相码的每一个码元都要调制为两个不同的电平，因而调制速率是码元速率的2倍。这无疑对信道的带宽提出了更高的要求，所以实现起来更困难也更昂贵。但由于其良好的抗噪声特性和自定时能力因此在局域网中仍被广泛应用)

Q8. 一般而言提到比特率就是用奈氏准则，提到信息传输速率就是用香农定理，关键的一点在于如果同时满足，需要取数值低的那一个值作为极限速率(参考王道考研课后习题)。

Q9.10代表速率10Mb/s BASE是baseband(基带)的缩写 5代表最多可支持5段500米的传输距离。 100BASE-T代表100Mb/s的基带传输，使用Twists(双绞线)

Q10.集线器(Hub)的本质是多端口的中继器，工作在物理层向上层(数据链路层)提供服务。中继器作用于信号的电气部分，可以将信号整形再生(而不是放大)。并且集线器只支持半双工的工作方式(不能解决冲突域),不能同时收发数据，在局域网的所有主机共享Hub的总带宽。

Q11.曼彻斯特编码是将时钟和数据包含在信号流中，在传输代码信息的同时，也将时钟同步信号一起传输到对方。曼彻斯特编码的每一个码元都被调制成两个电平，所以数据传输速率只有调制速率的1/2。

Q12.信噪比(dB)$=10log_{10}\frac{S}{N}$

Q13.信息传输速率=比特率*单个码元携带的比特数 $log_2V$

Q14.
- 机械特性:定义物理连接的的边界点,即接插装置。规定物理连接时所采用的规格、引线数目、引脚数量、排列情况。
- 电气特性:线路上信号的高低、阻抗匹配、传输速率、距离限制
- 功能特性：指明某一电平的电压所表示的意义，接口部件的信号线的用途
- 规程特性：定义各条物理线路的工作规程和时序关系。 