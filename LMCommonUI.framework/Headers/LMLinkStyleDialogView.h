//
//  LMLinkStyleDialogView.h
//  AFNetworking
//
//  Created by Hao on 2023/9/19.
//

#import <UIKit/UIKit.h>
#import "LMDialog.h"

NS_ASSUME_NONNULL_BEGIN

@interface LMLinkStyleDialogView : LMDialog

/// 设置链接的内容 
@property(nonatomic, strong)NSString *attributeString;

@property (nonatomic, copy)void(^linkAction)(LMDialog *dialogView, NSURL *url);

@end

NS_ASSUME_NONNULL_END
