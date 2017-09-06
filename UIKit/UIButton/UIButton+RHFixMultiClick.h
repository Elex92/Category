//
//  UIButton+RHFixMultiClick.h
//  SandCollections
//
//  Created by RuiHao on 2017/4/17.
//  Copyright © 2017年 RuiHao. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (RHFixMultiClick)
/**
 *  为按钮添加点击间隔 eventTimeInterval秒
 */
@property (nonatomic, assign) NSTimeInterval eventTimeInterval;
@end
