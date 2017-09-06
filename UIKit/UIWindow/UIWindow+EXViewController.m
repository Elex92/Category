//
//  UIWindow+EXViewController.m
//  Elex
//
//  Created by 沈丰元 on 2017/9/6.
//  Copyright © 2017年 沈丰元. All rights reserved.
//

#import "UIWindow+EXViewController.h"

@implementation UIWindow (EXViewController)
- (UIViewController*)topMostController
{
    UIViewController *topController = [self rootViewController];
    
    //  Getting topMost ViewController
    while ([topController presentingViewController])	topController = [topController presentingViewController];
    
    //  Returning topMost ViewController
    return topController;
}

- (UIViewController*)currentViewController;
{
    UIViewController *currentViewController = [self topMostController];
    
    while ([currentViewController isKindOfClass:[UINavigationController class]] && [(UINavigationController*)currentViewController topViewController])
        currentViewController = [(UINavigationController*)currentViewController topViewController];
    
    return currentViewController;
}
@end
