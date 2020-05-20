//
//  ViewController.m
//  TencentKeyboard
//
//  Created by lanlan on 2020/5/19.
//  Copyright © 2020 lanlan. All rights reserved.
//

#import "ViewController.h"
#import "LLInputController.h"
#import "THeader.h"
#import <AVFoundation/AVFoundation.h>
@interface ViewController ()<TInputControllerDelegate>
@property (nonatomic,strong) LLInputController * inputController;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = UIColor.whiteColor;
    _inputController = [[LLInputController alloc] init];
    _inputController.view.frame = CGRectMake(0, self.view.frame.size.height - TTextView_Height - Bottom_SafeHeight, self.view.frame.size.width, TTextView_Height + Bottom_SafeHeight);
    _inputController.view.autoresizingMask = UIViewAutoresizingFlexibleTopMargin;
    _inputController.delegate = self;
    [self addChildViewController:_inputController];
    [self.view addSubview:_inputController.view];
    
    
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.inputController reset];
}

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
    if ([cell.data.title isEqualToString:@"拍摄"]) {
        NSLog(@"点击了拍照");
        return;
    }
}


@end
