//
//  TUIImageCache.h
//  TXIMSDK_TUIKit_iOS
//
//  Created by annidyfeng on 2019/5/15.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface LLImageCache : NSObject

+ (instancetype)sharedInstance;

/**
 *  将图像资源添加进本地缓存中
 *
 *  @param path 本地缓存所在路径
 */
- (void)addResourceToCache:(NSString *)path;

/**
 *  从本地缓存获取图像资源
 *
 *  @param path 本地缓存所在路径
 */
- (UIImage *)getResourceFromCache:(NSString *)path;

/**
 *  将表情添加进本地缓存中
 *
 *  @param path 本地缓存所在路径
 */
- (void)addFaceToCache:(NSString *)path;

/**
 *  从本地缓存获取表情资源
 *
 *  @param path 本地缓存所在路径
 */
- (UIImage *)getFaceFromCache:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
