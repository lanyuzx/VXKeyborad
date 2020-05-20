//
//  AppDelegate.m
//  TencentKeyboard
//
//  Created by lanlan on 2020/5/19.
//  Copyright © 2020 lanlan. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:ViewController.new];
    [self.window makeKeyAndVisible];
    return YES;
}




@end
