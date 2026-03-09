# 第10章 - 编程练习

10.11　编程练习

  ★★1．当你拨打长途电话时，电话公司所保存的信息包括你拨打电话的日期和时间。它还包括三个电话号码：你使用的那个电话、你呼叫的那个电话以及你付账的那个电话。这些电话号码的每一个都由三个部分组成：区号、交换台和站号码。请为这些记账信息编写一个结构声明。

  ★★2．为一个信息系统编写一个声明，它用于记录每个汽车零售商的销售情况。每份销售记录必须包括下列数据。字符串值的最大长度不包括其结尾的NUL字节。

  　顾客名字(customer’s name)　　string(20)

  　顾客地址(customer’s address)　string(40)

  　模型(model)　　　　　　　　　　string(20)

  销售时可能出现三种不同类型的交易：全额现金销售、贷款销售和租赁。对于全额现金销售，你还必须保存下面这些附加信息：

  生产厂家建议零售价(manufacturer’s suggested retail price)　　　　　　　　　　　　　float

  实际售出价格(actual selling price)　　　float

  营业税(sales tax)　　　　　　　　　　　float

  许可费用(licensing fee)　　　　　　　　float

  对于租赁，你必须保存下面这些附加信息：

  生产厂家建议零售价(manufacturer’s suggested retail price)　　　　　　　　　　　　　float

  实际售出价格(actual selling price)　　　float

  预付定金(down payment)　　　　　　　float

  安全抵押(security deposit)　　　　　　　float

  月付金额(monthly payment)　　　　　　float

  租赁期限(lease term)　　　　　　　　　　int

  对于贷款销售，你必须保存下面这些附加信息：

  生产厂家建议零售价(manufacturer’s suggested retail price)　　　　　　　　　　　　　float

  实际售出价格(actual selling price)　　　float

  营业税(sales tax)　　　　　　　　　　　float

  许可费用(licensing fee)　　　　　　　　float

  预付定金(doun payment)　　　　　　　float

  贷款期限(loan duration)　　　　　　　　int

  贷款利率(interest rate)　　　　　　　　float

  月付金额(monthly payment)　　　　　float

  银行名称(name of bank)　　　　　　　string(20)

  3．计算机的任务之一就是对程序的指令进行解码，确定采取何种操作。在许多机器中，由于不同的指令具有不同的格式，解码过程被复杂化了。在某个特定的机器上，每个指令的长度都是16位，并实现了下列各种不同的指令格式。位是从右向左进行标记的。

  

  

  你的任务是编写一个声明，允许程序用这些格式中的任何一种形式对指令进行解释。你的声明同时必须有一个名叫addr的unsigned short类型字段，可以访问所有的16位值。在你的声明中使用typedef来创建一个新的类型，称为machine_inst。

  　给定下面的声明：
  　machine_inst　x;

  下面的表达式应该访问它所指定的位。
