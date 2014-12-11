//
//  CoreDataFetchDataSource.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 25/04/14.
//
//

@import CoreData;
@import UIKit;

/**
 *  Block which is responsible for configuring the given cell.
 *
 *  @param cell      A table view cell to configure.
 *  @param indexPath Index path of the given cell.
 */
typedef void(^CDAConfigureCellAtIndexPath)(UITableViewCell* cell, NSIndexPath* indexPath);

/**
 *  A `UITableViewDataSource` which works in conjunction with `CoreDataManager`.
 */
@interface CoreDataFetchDataSource : NSObject <UITableViewDataSource>

/** Block responsible for configuring cells. */
@property (nonatomic, copy) CDAConfigureCellAtIndexPath cellConfigurator;

/**
 *  Initializes a fetch data source.
 *
 *  @param fetchedResultsController The fetch results controller to use as source for data.
 *  @param tableView                The table view in which the data will be displayed.
 *  @param cellIdentifier           The reuse identifier used for cells in the table view.
 *
 *  @return An initialized fetch data source.
 */
-(id)initWithFetchedResultsController:(NSFetchedResultsController*)fetchedResultsController
                            tableView:(UITableView*)tableView
                       cellIdentifier:(NSString*)cellIdentifier;

/**
 *  Retrieve the object at a given index path.
 *
 *  @param indexPath The index path location of the object to retrieve.
 *
 *  @return An object or nil if none exists.
 */
-(id)objectAtIndexPath:(NSIndexPath*)indexPath;

/** Perform a fetch request from the database. */
-(void)performFetch;

@end
