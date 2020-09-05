---
title: python技巧
categories: python-skill
tags: python
toc: true
abbrlink: 5121
date: 2020-05-24 22:55:29
---


#### python 面经总结 day1

##### docstrings的理解
docstrings是一种注释风格，以三引号作为关键符，一般置于函数，类定义的下方，阐述函数的输入输出。可以使用魔法方法__doc__来查看。

##### 类型注释（函数注解）
python3的新特性 用于明确输入输出的类型，但是要注意的一点是python解释器并不为显式定义做任何事情，在解释器眼中，仍然是接受任何类型的输入输出，但是可以调用其他相关的第三方库，强制解释器对其输入输出进行规范，在输入类型不同时强制报错！<br>
```python 
def add(x:int , y:int) -> int :
	return x+y
# 两种函数定义是等价的，但是一种采用了类型注解（函数注解）
def add(x,y):
	return x+y

```
<!-- more -->


##### read,readline,readlines 简述区别
1. read方法将整个文件读成一个巨大的字符串，也可以指定读入多少个字节。<br>
2. readline方法则是读取成一个生成器，支持遍历和迭代，占用空间少，每调用一次方法则读取下一行。<br>
3. readlines方法将文本读取成列表，每一行作为list的元素，占用内存空间大.<br>

##### 闭包与装饰器
闭包:在一个内部函数对外部作用域的变量进行引用，并且外部函数的返回值是内部函数.
```python
def startAt(x):
	#内部函数
	def incrementBy(y):
		return x+y
	
	#return值是函数
	return incrementBy
#可以考虑用闭包写一个计时器的功能，查看每一个函数的运行时间，并且print出来
```
闭包是函数式编程的特性，提高了代码的复用性，可以用在函数调用时保存特定状态。
<br>
装饰器：使代码更加整洁，增强函数功能，@是装饰器的语法糖，
```python
def decorator(func):
	def wrapper(*args,**args):
		# 可以自定义传入的参数       
		print(func.__name__)
		# 返回传入的方法名参数的调用
		return func(*args,**args)
	# 返回内层函数函数名
	return wrapper
```
###### 传入参数的装饰器用三层函数定义
```python
def login(text):
	def decorator(func):
		def wrapper(*args,**args):
			print("%s-------%s"%(text,func.__name__))
			return func
		return wrapper
	return decorator
```

常见内置三种装饰器：@property @staticmethod @classmethod
1. @property:把类内方法当作属性调用，必须要有返回值，相当于getter。假如没有定义@func.setter修饰方法的话，那么就只是一个可读属性。
2. @staticmethod: 静态方法，不需要表示自身对象self和类对象的cls参数，就和使用函数一样。
3. @classmethod：不需要self参数，但是第一个参数是表示自身类的cls参数。

###### python的垃圾回收机制


由于目前不打算找实习了，该项目暂停！