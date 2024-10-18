template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
o_set<int> s;
// order_of_key() 返回 o_set 中小于x的元素个数
// int a = s.order_of_key(x);