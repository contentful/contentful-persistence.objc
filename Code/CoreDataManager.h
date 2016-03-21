//
//  CoreDataManager.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 14/04/14.
//
//

@import CoreData;

#import <ContentfulDeliveryAPI/CDAPersistenceManager.h>

@class CoreDataManager;

/**
 * Delegate protocol for providing customization of certain behaviours of `CoreDataManager`.
 */
@protocol CoreDataManagerDelegate <NSObject>

@optional

/**
 *  Called when adding a persistent store to the persistent store coordinator fails.
 *
 *  If not implemented, `CoreDataManager` will log the error to the console and `abort`.
 *
 *  @param dataManager The data manager which encountered the given error.
 *  @param error       The concrete error which occured.
 */
-(void)dataManager:(CoreDataManager*)dataManager didFailAddingStoreWithError:(NSError*)error;

/**
 *  Called when saving a managed object context fails.
 *
 *  If not implemented, `CoreDataManager` will log the error to the console and `abort`.
 *
 *  @param dataManager The data manager which encountered the given error.
 *  @param error       The concrete error which occured.
 */
-(void)dataManager:(CoreDataManager*)dataManager didFailSavingStoreWithError:(NSError*)error;

/**
 *  Called when the model of data on disk diverges from the one being used.
 *
 *  By default, all persisted data will be deleted, causing a resync of all data. If you want to instead
 *  perform a custom migration, implement this method in your delegate.
 *
 *  @param dataManager The data manager which encountered the incompatible model.
 *  @param metadata    Metadata of the persistent store being used.
 */
-(void)dataManager:(CoreDataManager*)dataManager handleMigrationWithMetadata:(NSDictionary*)metadata;

@end

#pragma mark -

/**
 *  A specialization of `CDAPersistenceManager` which allows you to use Core Data.
 *
 *  This is a pretty basic implementation, mostly based on the Core Data example project by Apple.
 *  Depending on your use case, you might want to modify this class to your liking - that's why it is
 *  not a part of the Contentful SDK itself.
 *
 */
@interface CoreDataManager : CDAPersistenceManager

/** @name Initialising the CoreDataManager Object */

/**
*  Initialise a new instance of `CoreDataManager`.
*
*  @param client        The client to be used for fetching Resources from Contentful.
*  @param dataModelName The name of your data model file (*.mom* or *.momd*).
*
*  @return An initialised instance of `CoreDataManager` or `nil` if an error occured.
*/
-(id)initWithClient:(CDAClient *)client dataModelName:(NSString*)dataModelName;

/**
 *  Initialise a new instance of `CoreDataManager`.
 *
 *  @param client        The client to be used for fetching Resources from Contentful.
 *  @param dataModelName The name of your data model file (*.mom* or *.momd*).
 *  @param query         Entries matching that query will be fetched.
 *
 *  @return An initialised instance of `CoreDataManager` or `nil` if an error occured.
 */
-(id)initWithClient:(CDAClient *)client
      dataModelName:(NSString*)dataModelName
              query:(NSDictionary *)query;

/** @name Fetching Resources */

/**
 *  Fetch Entries matching a predicate.
 *
 *  @param identifier   Identifier of the Content Type all Entries conform to.
 *  @param predicate    A string which will be converted to a `NSPredicate`.
 *
 *  @return An array of all Entries matching the given predicate.
 */
-(NSArray*)fetchEntriesOfContentTypeWithIdentifier:(NSString*)identifier
                                 matchingPredicate:(NSString*)predicate;

/**
 *  Fetch request for all Entries matching a predicate.
 *
 *  @param identifier   Identifier of the Content Type all Entries conform to.
 *  @param predicate A string which will be converted to a `NSPredicate`.
 *
 *  @return A fetch request for all Entries matching the given predicate.
 */
-(NSFetchRequest*)fetchRequestForEntriesOfContentTypeWithIdentifier:(NSString*)identifier
                                                  matchingPredicate:(NSString*)predicate;

/** @name Customizing Behaviour */

/** Delegate for providing custom error handling. */
@property (nonatomic, weak) id<CoreDataManagerDelegate> delegate;

/** @name Managed Object Context */

/**
 *  Concurrency type of the underlying managed object context of the receiver.
 *
 *  Set to `NSMainQueueConcurrencyType` by default, can only be changed prior to the first access
 *  of the data store. Set it to `NSConfinementConcurrencyType` for the behaviour of version 0.3.2 and
 *  earlier.
 *
 *  If you are using `NSPrivateQueueConcurrencyType`, make sure that you use the `performBlock:` or
 *  `performBlockAndWait:` methods of the management object context when accessing any data. See
 *  <http://oleb.net/blog/2014/06/core-data-concurrency-debugging/> for some tips on debugging Core
 *  Data concurrency issues.
 */
@property (nonatomic) NSManagedObjectContextConcurrencyType concurrencyType;

/** The default managed object context of the receiver. */
@property (nonatomic, readonly) NSManagedObjectContext *managedObjectContext;

/** The managed object model used by the receiver. */
@property (nonatomic, readonly) NSManagedObjectModel *managedObjectModel;

/** The persistent store coordinator used by the receiver. */
@property (nonatomic, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;

/** @name Testing Support */

/** 
 URL of the underlying store file.
 
 Only needed for unit testing.
 */
@property (nonatomic, readonly) NSURL* storeURL;

/** Delete all managed objects from the persistent store. */
-(void)deleteAll;

@end
