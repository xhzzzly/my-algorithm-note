## 杂项

当用`mp[object] == 0`来判断`object`在不在`mp`中时，如果`object`确实不存在，`mp`中会自动增加一项`mp[object] == 0`。此行为会影响`mp.empty()`的判断。