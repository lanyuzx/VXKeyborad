//
//  TUIKit.h
//  TUIKit
//
//  Created by kennethmiao on 2018/10/10.
//  Copyright © 2018年 Tencent. All rights reserved.
//
/** 腾讯云 TUIKit
 *
 *
 *  本类依赖于腾讯云 IM SDK 实现
 *  TUIKit 中的组件在实现 UI 功能的同时，调用 IM SDK 相应的接口实现 IM 相关逻辑和数据的处理
 *  您可以在TUIKit的基础上做一些个性化拓展，即可轻松接入IM SDK
 *
 *
 */

#import <UIKit/UIKit.h>
#import "LLKitConfig.h"
#import "LLImageCache.h"
#import "UIImage+TUIKIT.h"
#import "THeader.h"


@interface LLUIKit : NSObject

/**
 *  共享实例
 *  TUIKit为单例
 */
+ (instancetype)sharedInstance;

/**
 *  TUIKit配置类，包含默认表情、默认图标资源等
 */
@property LLKitConfig *config;

@end



