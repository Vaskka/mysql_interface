# datebase_interface DOC
> 2018 7 26

## QuerySet类
### 功能
提供了键值对形式的数据存储
可使用"[ ]"操作符进行访问
### 方法
#### QuerySet::QuerySet()
默认构造函数

#### string QuerySet::operator[](string key)
重载“[]”运算符
##### 参数
string key : key
##### 返回值
string 根据key得到的值

#### void QuerySet::setValue(string key, string value)
设置key-value映射
##### 参数
string key : key
string value : value

#### void QuerySet::setValue(string key, int value)
设置key-value映射
##### 参数
string key : key
int value : value

#### map<string, string> QuerySet::getDict() const;
得到内部map集合
##### 返回
map&lt;string, string&gt; map

## Executer_Filter类
Executer类内部变量，以键值对的形式实现过滤sql语句
### 方法
#### void Executer_Filter::addFilter(string key, string value)
增加一组键值组合
##### 参数
string key : key
string value : value

#### bool Executer_Filter::isEmpty()
检查是否为空
##### 返回
是空的 return true
不是空的 return false

#### string toString()
返回格式化的过滤语句 (规定Executer_Filter类的默认连接方法是AND)
##### 返回
string "key_1=1 AND key_2=2333 AND key_3=qwer" 


## 增加
<pre>
<code>
    // 构造包含插入数据的QuerySet类，列名为key，数据为值
    QuerySet data = QuerySet();

    data.setValue("col1", "value1");
    data.setValue("col2", 23333);
    data.setValue("col3", "another values");

    InsertExecuter ins = InsertExecuter("要插入的表名");
    ins.doInsert(data)

</code>
</pre>

## 删除
<pre>
<code>

    DeleteExecuter del = DeleteExecuter("要删除的表名");
    // 构造删除过滤器
    del.filter.addFilter("id", "2");
    del.doDelete()

</code>
</pre>

## 查询
<pre>
<code>

    SelectExecuter sel = SelectExecuter("要查询的表名");
    // 可选择构造查询过滤器
    // 不指定查询所有信息
    sel.filter.addFilter("id", "2");
    
    // 得到结果是一组结果集的向量
    vector&lt;QuerySet&gt; result = sel.doSelect();

</code>
</pre>

## 更改
<pre>
<code>
    // 构造包含更改数据的QuerySet类，列名为key，数据为值
    QuerySet data = QuerySet();

    data.setValue("col1", "value1");
    data.setValue("col2", 23333);
    data.setValue("col3", "another values");

    UpdateExecuter upd = UpdateExecuter("要更新的表名");

    // 构造过滤器
    upd.filter.addFilter("id", "2333");

    upd.doUpdate(data)
</code>
</pre>
