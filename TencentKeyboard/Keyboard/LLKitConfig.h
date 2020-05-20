//
//  TUIKitConfig.h
//  TUIKit
//
//  Created by kennethmiao on 2018/11/5.
//  Copyright © 2018年 Tencent. All rights reserved.
//
/**
 *
 *  需要注意的是表情包都是有版权限制的，请在上线的时候替换成自己的表情包，否则会面临法律风险
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LLFaceView.h"
#import "LLInputMoreCellData.h"

typedef NS_ENUM(NSInteger, TUIKitAvatarType) {
    TAvatarTypeNone,             /*矩形直角头像*/
    TAvatarTypeRounded,          /*圆形头像*/
    TAvatarTypeRadiusCorner,     /*圆角头像*/
};

@interface LLKitConfig : NSObject
/**
 * 表情列表（需要注意的是 TUIKit 里面的表情包都是有版权限制的，请在上线的时候替换成自己的表情包，否则会面临法律风险）
 */
@property (nonatomic, strong) NSArray<LLFaceGroup *> *faceGroups;
/**
 *  头像类型
 */
@property (nonatomic, assign) TUIKitAvatarType avatarType;
/**
 *  头像圆角大小
 */
@property (nonatomic, assign) CGFloat avatarCornerRadius;
/**
 *  默认头像图片
 */
@property (nonatomic, strong) UIImage *defaultAvatarImage;
/**
 *  默认群组头像图片
 */
@property (nonatomic, strong) UIImage *defaultGroupAvatarImage;

+ (LLKitConfig *)defaultConfig;

@end
