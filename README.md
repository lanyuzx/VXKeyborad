# VXKeyborad
iOS开发之仿微信表情键盘
#今天刚好520,单身的iOS狗扎心不O(∩_∩)O哈哈~ 好了,不扯犊子,进入话题
#### 公司最近正在开发直播项目,为了省钱接了一个听都没听过的直播,emmmm,不想多少,接入了各种问题,唯一头疼的就是表情键盘,刚开始网上摸爬滚打,不是没设配iPhoneX以上的设备,就是动画写的不尽人意,开发接入尾声时间,忽然想起之前接过一个私活,腾讯云直播里面有表情键盘,果断pod一下,把键盘单拎出来,各种改各种搓,终于在快下班时候成功了,哈哈,在此分享给哪些爬坑的小伙伴们,同时感谢腾讯云前辈们造的轮子![8`ZEOT}%V7WMQWFLJRH5QHM.jpg](https://upload-images.jianshu.io/upload_images/1510469-c105c22e78661d44.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 效果图
![未命名.gif](https://upload-images.jianshu.io/upload_images/1510469-3a84acde4d20a103.gif?imageMogr2/auto-orient/strip)

###### 简单修了一些业务上的bug
1. 修复了表情键盘只能删除表情的问题
2. 删除了一些腾讯云里面无用的文件以及代码
#站在前辈们的肩膀上开发:
- 激动人人心的时候到来了,上面都是扯犊子,下面咱们看看怎么用吧 上硬菜O(∩_∩)O哈哈~
```
    _inputController = [[LLInputController alloc] init];
   _inputController.view.frame = CGRectMake(0, self.view.frame.size.height - TTextView_Height - Bottom_SafeHeight, self.view.frame.size.width, TTextView_Height + Bottom_SafeHeight);
    _inputController.view.autoresizingMask = UIViewAutoresizingFlexibleTopMargin;
    _inputController.delegate = self;
    [self addChildViewController:_inputController];
    [self.view addSubview:_inputController.view];
```
- 是不是惊了 就这么简单 ![1.png](https://upload-images.jianshu.io/upload_images/1510469-debce871cd96d593.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 当然还要遵循代理 实现代理方法
```
- (void)inputController:(LLInputController *)inputController didChangeHeight:(CGFloat)height
{
    __weak typeof(self) ws = self;
    [UIView animateWithDuration:0.3 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
        CGRect msgFrame = CGRectMake(0, 0, CGRectGetWidth(self.view.frame), CGRectGetHeight(self.view.frame) - CGRectGetHeight(self.inputController.view.frame));
        msgFrame.size.height = ws.view.frame.size.height - height;
        CGRect inputFrame = ws.inputController.view.frame;
        inputFrame.origin.y = msgFrame.origin.y + msgFrame.size.height;
        inputFrame.size.height = height;
        ws.inputController.view.frame = inputFrame;

    } completion:nil];
}
- (void)inputController:(LLInputController *)inputController didSendMessage:(id)msg {
    if ([msg isKindOfClass:[NSString class]]) {
        NSLog(@"发送的文本消息 内容====%@",msg);
        return;
    }
    if ([msg isKindOfClass:[AVURLAsset class]]) {
       AVURLAsset *audioAsset = msg;
        int duration = (int)CMTimeGetSeconds(audioAsset.duration);
        int length = (int)[[[NSFileManager defaultManager] attributesOfItemAtPath:[audioAsset.URL path] error:nil] fileSize];
        NSLog(@"发送的语音消息 语音长度====%d 长度== %d",duration,length);
        
        return;
    }
}
- (void)inputController:(LLInputController *)inputController didSelectMoreCell:(LLInputMoreCell *)cell {
    if ([cell.data.title isEqualToString:@"相册"]) {
        NSLog(@"点击了相册");
        return;
    }
    if ([cell.data.title isEqualToString:@"拍照"]) {
        NSLog(@"点击了拍照");
        return;
    }
}
```
![191A69CF-1854-4A26-9B82-2869F0B4BBBB.png](https://upload-images.jianshu.io/upload_images/1510469-8d7e1ad3f8aa0e99.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

-结束啦 
