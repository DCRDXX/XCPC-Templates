// n堆Nim博弈 异或和为0，先手必败
// 阶梯博弈(Nim博弈变种) 奇数节点异或和为0，先手必败
// 树上阶梯博弈和阶梯博弈同理

// SG 定理
// SG(x) == 0 x为必败点,否则为必胜点
// SG(x) = mex{SG(y) | x can go to y} // y 是小状态 x 是大状态
// 游戏的和的SG值是他们SG值的xor