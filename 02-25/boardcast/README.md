# 广播通信流程
## 服务器端
1. 创建套接字 - socket
2. fd绑定服务器IP和端口
3. 初始化客户端端口信息，设置IP为广播地址
4. 设置广播权限
5. 通信

## 客户端
1. 创建套接字
2. 显示绑定IP("0.0.0.0")和端口
3. 接收数据 - server数据

○ 适用范围
 只适用于局域网