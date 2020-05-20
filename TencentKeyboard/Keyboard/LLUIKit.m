//
//  TUIKit.m
//  TUIKit
//
//  Created by kennethmiao on 2018/10/12.
//  Copyright © 2018年 Tencent. All rights reserved.
//

#import "LLUIKit.h"
#import "THeader.h"
@interface LLUIKit ()
@end

@implementation LLUIKit

+ (instancetype)sharedInstance
{
    static LLUIKit *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[LLUIKit alloc] init];
    });
    return instance;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _config = [LLKitConfig defaultConfig];
        [self createCachePath];
    }
    return self;
}

- (void)createCachePath
{
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if(![fileManager fileExistsAtPath:TUIKit_Image_Path]){
        [fileManager createDirectoryAtPath:TUIKit_Image_Path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    if(![fileManager fileExistsAtPath:TUIKit_Video_Path]){
        [fileManager createDirectoryAtPath:TUIKit_Video_Path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    if(![fileManager fileExistsAtPath:TUIKit_Voice_Path]){
        [fileManager createDirectoryAtPath:TUIKit_Voice_Path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    if(![fileManager fileExistsAtPath:TUIKit_File_Path]){
        [fileManager createDirectoryAtPath:TUIKit_File_Path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    if(![fileManager fileExistsAtPath:TUIKit_DB_Path]){
        [fileManager createDirectoryAtPath:TUIKit_DB_Path withIntermediateDirectories:YES attributes:nil error:nil];
    }
}

@end
