#LMDialog的使用


### 弹窗图片+大标题+描述信息+超链接文本+输入框+复选框+按钮效果
```
    //title和message可以为空
    LMDialog * dialog = [LMDialog dialogWithTitle:@"title" message:@"this is message"];

    //添加图片
    [dialog addImage:[UIImage imageNamed:@"new_version_blankpage"]];
    
    //添加超链接
    [dialog addLinkAction:[LMDialogLinkAction linkActionWithDesc:@"这是超链接的文本描述,理论上随便写." URL:[NSURL URLWithString:@"www.baidu.com"] range:NSMakeRange(2, 3) handler:^(LMDialogLinkAction * _Nonnull action, LMDialogLinkData * _Nonnull linkData) {
        //to do
    }]];
    
    //添加文本输入框
    [dialog addTextField:[LMDialogTextField textField]];
    
    //添加复选框
    [dialog addCheckBox:[LMDialogCheckBox checkBoxWithTitle:@"check box" handler:^(LMDialogCheckBox * _Nonnull checkBox) {
        //check box selected or unselected
    }]];
    
    //添加按钮点击事件
    [dialog addAction:[LMDialogAction actionWithTitle:@"cancel" style:LMDialogActionStyleCancel handler:^(LMDialogAction * _Nonnull action) {
        //to do
    }]];
    
    [dialog addAction:[LMDialogAction actionWithTitle:@"OK" style:LMDialogActionStyleDefault handler:^(LMDialogAction * _Nonnull action) {
        //to do
    }]];
    
    //展示
    [dialog show];
        ///present到指定控制器
//    [dialog presentToViewController:self];
        ///add 到指定view视图
//    [dialog displayToView:[UIApplication sharedApplication].keyWindow];

```
