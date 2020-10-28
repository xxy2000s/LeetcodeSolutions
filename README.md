<h1 align = "center">北京邮电大学</h1>
<h2 align = "center">信息网络建模与仿真实验报告</h2>
<center>
    <img src = "https://pictures.xiaxuyang.com/img/image-20201028170257787.png"</>
</center>






### 实验一：均匀分布随机数的产生



- #### 1、实验原理
 (1) 线性同余法:
  - 采用下述公式产生随机数：
  $$x_{n+1}=\left[a x_{n}+b\right] \bmod (m)$$

- 其中$x_n$是第n个随机数，a为乘子，b为增量，m为模数，$0≤x_0<m$ 为随机数源或种子（seed），均为非负整数。
- 令 $U_n≔x_n∕m$，则可得到[0,1)区间上的随机数。
- 若a!=0, b!=0，称为混合同余法 
- 若a=1，b!=0，称为加同余法
- 若a!=0, b=0，称为乘同余法
- 研究表明，乘同余法优于加同余法，而混合同余法与简单的乘同余法相比并无显著优点。
- 所以本次实验采用乘同余法 各参数a=16807，b=0，m=2147483647。

(2)梅森旋转法：
- 梅森旋转算法是迄今为止最好的随机数发生器之一，可以产生高质量的伪随机数，并且效率高效，弥补了传统伪随机数生成器的不足。
- 梅森旋转算法的最长周期取自一个梅森素数，由此命名为梅森旋转算法。常见的两种为基于32位的MT19937-32和基于64位的MT19937-64。
- #### 2、实现结果展示

<center>
    <img src = "https://pictures.xiaxuyang.com/img/image-20201026165817552.png"</>
</center>
<center>
    <img src = "https://pictures.xiaxuyang.com/img/image-20201026165846803.png"</>
</center>

- #### 3、实验结果分析

线性同余法：如图2所示，在[0,1]均分的十个区间内，各区间内随机数量大致相同，均为10^5个左右，并且随机数总数个数越多越符合均匀分布的规律。以下为随机数的统计量，均保留三位小数：
	实际值	理论值
均值	0.4998	0.500
方差	0.0828	0.083
标准差	0.2888	0.289
概率密度（PDF）为在1上下微小波动的曲线，与理论值大致吻合。
分布函数（CDF）为斜率为1的过原点的直线，与理论值大致吻合。
MT法：如图3所示，在[0,1]均分的十个区间内，各区间内随机数量大致相同，均为10^5个左右，符合均匀分布规律。以下为其统计量：
	实际值	理论值
均值	0.5002	0.500
方差	0.0832	0.083
标准差	0.2888	0.289



- #### 4、其他





### 实验二：Pareto分布



- #### 1、实验原理

- #### 2、实现结果展示

<center>
    <img src = "https://pictures.xiaxuyang.com/img/image-20201026170010732.png"</>
</center>

- #### 3、实验结果分析

- #### 4、其他




### 实验三：标准高斯分布随机数



- #### 1、实验原理

- #### 2、实现结果展示

<center>
    <img src = "https://pictures.xiaxuyang.com/img/image-20201026170137756.png
"</>
</center> 

- #### 3、实验结果分析

- #### 4、其他




### 实验四：混合高斯随机变量



- #### 1、实验原理

- #### 2、实现结果展示

<center>
    <img src = "https://pictures.xiaxuyang.com/img/image-20201026170230503.png"</>
</center>


- #### 3、实验结果分析

- #### 4、其他




### 实验五：泊松过程



- #### 1、实验原理

- #### 2、实现结果展示

<center>
    <img src = "https://pictures.xiaxuyang.com/img/image-20201026170350064.png"</>
</center>

- #### 3、实验结果分析

- #### 4、其他