# Coding Designers of Moon Tech 第2轮迭代设计

## __Moon Tech Group Member:__
* Mr.Dynamic
* Mrs.Kylin
* Mr.DaydreamFactory
- - - 

### 设计目标：
* 在第一轮迭代的基础上实现对战游戏网络版

* 对战需要在互联网上进行（不是局域网或者本机）

- - - 

### _Hint:_
* 采用客户机/服务器模式（Client/Server）
* 采用客户机/服务器模式（Client/Server）
* 云服务器可以租用，记得打开对应的端口，否则外网无法访问
* 服务器程序可以用任何语言开发
---

- - -
## 设计思路：
1. 通过socket协议实现服务器端（Server）与客户端（Client）的沟通联系；
2. 客户端将落子数据打包成坐标格式，传给服务器，由服务器处理转发给连接上的另一客户端，实现通过公网的实时五子棋网络对战。
---
## 实现方式：
* 通过腾讯云租赁VPS，安装Centos 7.6镜像系统，更新服务器gcc库至gcc-12.1.0版本（以此解决gcc版本过低导致的找不到头文件的问题）
![](https://github.com/MrDynimate/QTproject/images/running.jpg）
* 关闭Centos的FireWall，开放所有端口,以便实现服务器与客户端之间的连接；
* “三次握手，四次挥手”之后建立服务器与客户端之间的连接；
