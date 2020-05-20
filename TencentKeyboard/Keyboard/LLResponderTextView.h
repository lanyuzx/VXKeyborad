//
//  TResponderTextView.h
//  TUIKit
//
//  Created by kennethmiao on 2018/10/25.
//  Copyright © 2018年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
@class LLResponderTextView;
@protocol LLResponderTextViewDelegate <UITextViewDelegate>

- (void)textViewDeleteBackward:(LLResponderTextView *)textView;

@end
@interface LLResponderTextView : UITextView
@property (nonatomic, weak) UIResponder *overrideNextResponder;
@property(nonatomic ,weak) id<LLResponderTextViewDelegate> responderDelegate;

@property (nonatomic, copy) NSString * placeHolder;

@property (nonatomic, strong) UIColor * placeHolderTextColor;

- (NSUInteger)numberOfLinesOfText;
@end
