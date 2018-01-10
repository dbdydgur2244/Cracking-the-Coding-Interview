# Chapter 5: Bit Manipulation

## Arithmetic vs. Logical Right Shift

### Arithmetic Right Shift

Arithmetic right shift essentially divides by two

즉, 산술적으로 (roughly) 2로 나누는 거.

'>>'로 가능

### Logical Right Shift

The logical right shift does what we would visually see as shifting the bits

보이는 bit 그대로 bit shift. sign bit는 0으로 됨.

'>>>'로 가능



## Common Bit Tasks: Getting and Setting

### Get Bit

i번째 bit를 얻음. 단순히 1을 i번 left shift한 것과 And 연산하면 됨.

```c++
bool getBit(init num, int i){
    return ((num & (1 << i)) != 0);
}
```



### Set Bit

i번째 bit를 1로 세팅함.

```c++
int setBit(init num, int i){
    return num | (1 << i);
}
```



### Clear Bit

i번째 bit를 clear함. 0으로 바꾸는 것을 말하는 듯. 과정은 SetBit의 반대로하면 됨.

```c++
int clearBit(int num, int i){
    int mask = ~(1 << i);
    return num & mask;
}
```



### Update Bit

i번째 bit를 해당하는 값으로 바꿈.

0은 left shift를 해도 0인 것을 이용.

```c++
int updateBit(int num, int i, bool bit){
    int value = bit ? 1 : 0;
    int mask = ~(1 << i);
    return (num & mask) | (value << i);
}
```



## 재밌는 것들

1. [1부터 n까지의 xor의 결과](https://www.geeksforgeeks.org/calculate-xor-1-n/)

   ​

2. [a부터 b까지의 xor 결과](https://stackoverflow.com/questions/10670379/find-xor-of-all-numbers-in-a-given-range)



