---
title: the model of Cache
tag: csapp
abbrlink: a0f7cd5
date: 2020-07-10 09:12:20
---

---
Cache 位于存储器层次结构的顶层，通常由SRAM构成 Cache的本质是利用了程序的局部性。
### Cache缓存交换
为了便于Cache和主存之间交换信息，Cache和主存都被划分为相等的块，Cache块又被称为Cache行，每块由若干字节组成。当CPU发出都请求时，若访存地址在Cache中命中，就将此地址转换成Cache地址，直接对Cache进行读操作；若cache不命中，则访问主存，并把此字所在的块从主存调入Cache中。若cache已经满了，则需根据某种替换算法，替换掉别的块。
> tips : CPU与cache之间的数据交换以字为单位，而cache与主存之间的数据交换则以Cache块为单位。

- 命中率：CPU欲访问的信息已在Cache中的比率称为Cache的命中率。设一个程序执行期间，cache的总命中次数为N_c ,访问主存的总次数为N_m,则命中率H为
<p align="center">H = N_c/(N_c+N_m)</p>

- 平均访存时间： 设t_c为命中时的Cache访问时间，t_m为未命中时的访问时间，1-H表示未命中率，则Cache-主存系统的平均访问时间T_a为，
<p>T_a =  H\*t_c + (1-H)\*t_m</p>

### Cache和主存的映射方式
Cache行中的信息是主存中某个块的副本，地址映射是指主存地址空间映射到Cache地址空间，即把存放在主存的信息按照某种规则装入Cache中。

1. 直接映射 ：主存中的每一块只能装入Cache中的唯一位置。且直接映射无需使用替换算法，但此方法的块冲突概率最高，空间利用率最低，直接映射的关系可定义为：
<p>j = i mod 2^c </p>

> 其中 j为Cache的块号，i为主存的块号，2^c是Cache中的总块数。\n
其结构为 第2^n块 只能放在Cache的第零行; 第(2^n)+1块只能放在Cache的第1行;依次类推

由映射函数可以看出，主存块号i的低c位正好是他要装入的Cache行号，给每个Cache行设置一个长为 t = m - c 的tag，当主存某块调入cache后，就将其块号的高t位设置在对应Cache行的标记中，