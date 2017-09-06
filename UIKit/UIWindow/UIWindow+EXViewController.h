//
//  UIWindow+EXViewController.h
//  Elex
//
//  Created by 沈丰元 on 2017/9/6.
//  Copyright © 2017年 沈丰元. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIWindow (EXViewController)
/**
 *  当前窗体的最上面的控制器
 *
 *  @return 控制器
 */
- (UIViewController*)topMostController;
/**
 *  当前窗体的控制器
 *
 *  @return 控制器
 */
- (UIViewController*)currentViewController;
@end
