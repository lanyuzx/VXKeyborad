//
//  THelper.h
//  TUIKit
//
//  Created by kennethmiao on 2018/11/1.
//  Copyright © 2018年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void (^TAsyncImageComplete)(NSString *path, UIImage *image);

@interface LLHelper : NSObject
+ (NSString *)genFileName:(NSString *)uuid;
+ (NSString *)genVoiceName:(NSString *)uuid withExtension:(NSString *)extent;
+ (BOOL)isAmr:(NSString *)path;
+ (BOOL)convertAmr:(NSString*)amrPath toWav:(NSString*)wavPath;
+ (BOOL)convertWav:(NSString*)wavPath toAmr:(NSString*)amrPath;
+ (void)asyncDecodeImage:(NSString *)path complete:(TAsyncImageComplete)complete;

+ (BOOL)isEmoji:(NSString *)emoji;
@end
