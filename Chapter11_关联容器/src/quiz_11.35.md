在 build_map 中，如果进行如下改写，会有什么效果？

`trans_map[key] = value.substr(1);` 改写为：  
`trans_map.insert({key, value.substr(1)});`

> 答：如果要插入的转换规则中包含同一个关键字的多条记录，使用前者会保留该关键字的最后一条记录，使用后者会保留该关键字的第一条记录。
