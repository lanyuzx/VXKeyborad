

#import <UIKit/UIKit.h>

@interface LLInputMoreCellData : NSObject

/**
 *  单元图标
 *  各个单元的图标有所不同，用于形象表示该单元所对应的功能。
 */
@property (nonatomic, strong) UIImage *image;

/**
 *  单元名称
 *  各个单元的名称有所不同（比如拍摄、录像、文件、相册等），用于在图标下方以文字形式展示单元对应的功能。
 */
@property (nonatomic, strong) NSString *title;

/**
 *  “相册”单元所对应的数据源。用于存放相册单元所需的各类信息与数据。
 */
@property (class, nonatomic, assign) LLInputMoreCellData *photoData;

/**
 *  “拍摄”单元所对应的数据源。用于存放拍摄单元所需的各类信息与数据。
 */
@property (class, nonatomic, assign) LLInputMoreCellData *pictureData;

/**
 *  “视频”单元所对应的数据源。用于存放视频单元所需的各类信息与数据。
 */
@property (class, nonatomic, assign) LLInputMoreCellData *videoData;

/**
 *  “文件”单元所对应的数据源。用于存放文件单元所需的各类信息与数据。
 */
@property (class, nonatomic, assign) LLInputMoreCellData *fileData;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 【功能说明】更多单元，即在更多视图中显示的单元。
 *  更多单元负责在更多视图中显示，向用户展示更多视图中包含的功能。同时作为各个功能的入口，相应用户的交互事件。
 */
@interface LLInputMoreCell : UICollectionViewCell

/**
 *  更多单元对应的图标，从 TUIInputMoreCellData 的 iamge 中获取。
 *  各个单元的图标有所不同，用于形象表示该单元所对应的功能。
 */
@property (nonatomic, strong) UIImageView *image;

/**
 *  更多单元对应的标签。
 *  其文本内容从 TUIInputMoreCellData 的 title 中获取。
 *  各个单元的名称有所不同（比如拍摄、录像、文件、相册等），用于在图标下方以文字形式展示单元对应的功能。
 */
@property (nonatomic, strong) UILabel *title;

/**
 *  更多单元对应的数据源
 *  存放更多单元所需的信息与数据。
 */
@property (nonatomic, strong) LLInputMoreCellData *data;

/**
 *  根据消息源填充“更多”单元。
 *  包括 iamge、title 的赋值与 frame 的设定。
 *
 *  @param data 负责存放数据的数据源。
 */
- (void)fillWithData:(LLInputMoreCellData *)data;

/**
 *  获取大小
 *  负责获取当前“更多”单元在 UI 上的显示面积。
 */
+ (CGSize)getSize;
@end



