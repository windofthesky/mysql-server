/*
 Copyright (c) 2012, Oracle and/or its affiliates. All rights reserved.

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; version 2 of the License.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
*/
/*
 * ndbjtie_unit_tests_classes.cpp
 */

#include <assert.h>
#include <string.h>

#include "ndbjtie_unit_tests_consts.hpp"
#include "NdbApi.hpp"
//#include "NdbError.hpp"

// name/value pair
struct Constant {
    const char * const name;
    const long long value;
};

// the list of defined constants
static Constant constants[] = {
    { "com.mysql.ndbjtie.ndbapi.Ndb$PartitionSpecConst$SpecType.PS_NONE",
      Ndb::PartitionSpec::/*_enum SpecType_*/PS_NONE },
    { "com.mysql.ndbjtie.ndbapi.Ndb$PartitionSpecConst$SpecType.PS_USER_DEFINED",
      Ndb::PartitionSpec::/*_enum SpecType_*/PS_USER_DEFINED },
    { "com.mysql.ndbjtie.ndbapi.Ndb$PartitionSpecConst$SpecType.PS_DISTR_KEY_PART_PTR",
      Ndb::PartitionSpec::/*_enum SpecType_*/PS_DISTR_KEY_PART_PTR },
    { "com.mysql.ndbjtie.ndbapi.Ndb$PartitionSpecConst$SpecType.PS_DISTR_KEY_RECORD",
      Ndb::PartitionSpec::/*_enum SpecType_*/PS_DISTR_KEY_RECORD },
    { "com.mysql.ndbjtie.ndbapi.NdbBlob$State.Idle",
      NdbBlob::/*_enum State_*/Idle },
    { "com.mysql.ndbjtie.ndbapi.NdbBlob$State.Prepared",
      NdbBlob::/*_enum State_*/Prepared },
    { "com.mysql.ndbjtie.ndbapi.NdbBlob$State.Active",
      NdbBlob::/*_enum State_*/Active },
    { "com.mysql.ndbjtie.ndbapi.NdbBlob$State.Closed",
      NdbBlob::/*_enum State_*/Closed },
    { "com.mysql.ndbjtie.ndbapi.NdbBlob$State.Invalid",
      NdbBlob::/*_enum State_*/Invalid },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$ArrayType.ArrayTypeFixed",
      NdbDictionary::Column::/*_enum ArrayType_*/ArrayTypeFixed },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$ArrayType.ArrayTypeShortVar",
      NdbDictionary::Column::/*_enum ArrayType_*/ArrayTypeShortVar },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$ArrayType.ArrayTypeMediumVar",
      NdbDictionary::Column::/*_enum ArrayType_*/ArrayTypeMediumVar },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$StorageType.StorageTypeMemory",
      NdbDictionary::Column::/*_enum StorageType_*/StorageTypeMemory },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$StorageType.StorageTypeDisk",
      NdbDictionary::Column::/*_enum StorageType_*/StorageTypeDisk },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Undefined",
      NdbDictionary::Column::/*_enum Type_*/Undefined },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Tinyint",
      NdbDictionary::Column::/*_enum Type_*/Tinyint },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Tinyunsigned",
      NdbDictionary::Column::/*_enum Type_*/Tinyunsigned },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Smallint",
      NdbDictionary::Column::/*_enum Type_*/Smallint },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Smallunsigned",
      NdbDictionary::Column::/*_enum Type_*/Smallunsigned },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Mediumint",
      NdbDictionary::Column::/*_enum Type_*/Mediumint },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Mediumunsigned",
      NdbDictionary::Column::/*_enum Type_*/Mediumunsigned },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Int",
      NdbDictionary::Column::/*_enum Type_*/Int },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Unsigned",
      NdbDictionary::Column::/*_enum Type_*/Unsigned },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Bigint",
      NdbDictionary::Column::/*_enum Type_*/Bigint },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Bigunsigned",
      NdbDictionary::Column::/*_enum Type_*/Bigunsigned },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Float",
      NdbDictionary::Column::/*_enum Type_*/Float },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Double",
      NdbDictionary::Column::/*_enum Type_*/Double },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Olddecimal",
      NdbDictionary::Column::/*_enum Type_*/Olddecimal },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Olddecimalunsigned",
      NdbDictionary::Column::/*_enum Type_*/Olddecimalunsigned },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Decimal",
      NdbDictionary::Column::/*_enum Type_*/Decimal },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Decimalunsigned",
      NdbDictionary::Column::/*_enum Type_*/Decimalunsigned },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Char",
      NdbDictionary::Column::/*_enum Type_*/Char },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Varchar",
      NdbDictionary::Column::/*_enum Type_*/Varchar },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Binary",
      NdbDictionary::Column::/*_enum Type_*/Binary },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Varbinary",
      NdbDictionary::Column::/*_enum Type_*/Varbinary },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Datetime",
      NdbDictionary::Column::/*_enum Type_*/Datetime },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Date",
      NdbDictionary::Column::/*_enum Type_*/Date },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Blob",
      NdbDictionary::Column::/*_enum Type_*/Blob },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Text",
      NdbDictionary::Column::/*_enum Type_*/Text },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Bit",
      NdbDictionary::Column::/*_enum Type_*/Bit },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Longvarchar",
      NdbDictionary::Column::/*_enum Type_*/Longvarchar },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Longvarbinary",
      NdbDictionary::Column::/*_enum Type_*/Longvarbinary },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Time",
      NdbDictionary::Column::/*_enum Type_*/Time },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Year",
      NdbDictionary::Column::/*_enum Type_*/Year },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ColumnConst$Type.Timestamp",
      NdbDictionary::Column::/*_enum Type_*/Timestamp },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$EventDurability.ED_UNDEFINED",
      NdbDictionary::Event::/*_enum EventDurability_*/ED_UNDEFINED },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$EventDurability.ED_PERMANENT",
      NdbDictionary::Event::/*_enum EventDurability_*/ED_PERMANENT },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$EventReport.ER_UPDATED",
      NdbDictionary::Event::/*_enum EventReport_*/ER_UPDATED },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$EventReport.ER_ALL",
      NdbDictionary::Event::/*_enum EventReport_*/ER_ALL },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$EventReport.ER_SUBSCRIBE",
      NdbDictionary::Event::/*_enum EventReport_*/ER_SUBSCRIBE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_INSERT",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_INSERT },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_DELETE",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_DELETE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_UPDATE",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_UPDATE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_DROP",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_DROP },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_ALTER",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_ALTER },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_CREATE",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_CREATE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_GCP_COMPLETE",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_GCP_COMPLETE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_CLUSTER_FAILURE",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_CLUSTER_FAILURE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_STOP",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_STOP },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_NODE_FAILURE",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_NODE_FAILURE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_SUBSCRIBE",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_SUBSCRIBE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_UNSUBSCRIBE",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_UNSUBSCRIBE },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$EventConst$TableEvent.TE_ALL",
      NdbDictionary::Event::/*_enum TableEvent_*/TE_ALL },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$IndexConst$Type.Undefined",
      NdbDictionary::Index::/*_enum Type_*/Undefined },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$IndexConst$Type.UniqueHashIndex",
      NdbDictionary::Index::/*_enum Type_*/UniqueHashIndex },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$IndexConst$Type.OrderedIndex",
      NdbDictionary::Index::/*_enum Type_*/OrderedIndex },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$NdbRecordFlags.RecMysqldShrinkVarchar",
      NdbDictionary::/*_enum NdbRecordFlags_*/RecMysqldShrinkVarchar },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$NdbRecordFlags.RecMysqldBitfield",
      NdbDictionary::/*_enum NdbRecordFlags_*/RecMysqldBitfield },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$FragmentType.FragUndefined",
      NdbDictionary::Object::/*_enum FragmentType_*/FragUndefined },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$FragmentType.FragSingle",
      NdbDictionary::Object::/*_enum FragmentType_*/FragSingle },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$FragmentType.FragAllSmall",
      NdbDictionary::Object::/*_enum FragmentType_*/FragAllSmall },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$FragmentType.FragAllMedium",
      NdbDictionary::Object::/*_enum FragmentType_*/FragAllMedium },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$FragmentType.FragAllLarge",
      NdbDictionary::Object::/*_enum FragmentType_*/FragAllLarge },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$FragmentType.DistrKeyHash",
      NdbDictionary::Object::/*_enum FragmentType_*/DistrKeyHash },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$FragmentType.DistrKeyLin",
      NdbDictionary::Object::/*_enum FragmentType_*/DistrKeyLin },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$FragmentType.UserDefined",
      NdbDictionary::Object::/*_enum FragmentType_*/UserDefined },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$State.StateUndefined",
      NdbDictionary::Object::/*_enum State_*/StateUndefined },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$State.StateOffline",
      NdbDictionary::Object::/*_enum State_*/StateOffline },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$State.StateBuilding",
      NdbDictionary::Object::/*_enum State_*/StateBuilding },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$State.StateDropping",
      NdbDictionary::Object::/*_enum State_*/StateDropping },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$State.StateOnline",
      NdbDictionary::Object::/*_enum State_*/StateOnline },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$State.StateBackup",
      NdbDictionary::Object::/*_enum State_*/StateBackup },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$State.StateBroken",
      NdbDictionary::Object::/*_enum State_*/StateBroken },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Store.StoreUndefined",
      NdbDictionary::Object::/*_enum Store_*/StoreUndefined },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Store.StoreNotLogged",
      NdbDictionary::Object::/*_enum Store_*/StoreNotLogged },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Store.StorePermanent",
      NdbDictionary::Object::/*_enum Store_*/StorePermanent },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.TypeUndefined",
      NdbDictionary::Object::/*_enum Type_*/TypeUndefined },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.SystemTable",
      NdbDictionary::Object::/*_enum Type_*/SystemTable },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.UserTable",
      NdbDictionary::Object::/*_enum Type_*/UserTable },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.UniqueHashIndex",
      NdbDictionary::Object::/*_enum Type_*/UniqueHashIndex },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.OrderedIndex",
      NdbDictionary::Object::/*_enum Type_*/OrderedIndex },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.HashIndexTrigger",
      NdbDictionary::Object::/*_enum Type_*/HashIndexTrigger },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.IndexTrigger",
      NdbDictionary::Object::/*_enum Type_*/IndexTrigger },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.SubscriptionTrigger",
      NdbDictionary::Object::/*_enum Type_*/SubscriptionTrigger },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.ReadOnlyConstraint",
      NdbDictionary::Object::/*_enum Type_*/ReadOnlyConstraint },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.TableEvent",
      NdbDictionary::Object::/*_enum Type_*/TableEvent },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.Tablespace",
      NdbDictionary::Object::/*_enum Type_*/Tablespace },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.LogfileGroup",
      NdbDictionary::Object::/*_enum Type_*/LogfileGroup },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.Datafile",
      NdbDictionary::Object::/*_enum Type_*/Datafile },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$Object$Type.Undofile",
      NdbDictionary::Object::/*_enum Type_*/Undofile },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ObjectConst$Status.New",
      NdbDictionary::Object::/*_enum Status_*/New },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ObjectConst$Status.Changed",
      NdbDictionary::Object::/*_enum Status_*/Changed },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ObjectConst$Status.Retrieved",
      NdbDictionary::Object::/*_enum Status_*/Retrieved },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ObjectConst$Status.Invalid",
      NdbDictionary::Object::/*_enum Status_*/Invalid },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$ObjectConst$Status.Altered",
      NdbDictionary::Object::/*_enum Status_*/Altered },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$RecordType.TableAccess",
      NdbDictionary::/*_enum RecordType_*/TableAccess },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$RecordType.IndexAccess",
      NdbDictionary::/*_enum RecordType_*/IndexAccess },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$TableConst$SingleUserMode.SingleUserModeLocked",
      NdbDictionary::Table::/*_enum SingleUserMode_*/SingleUserModeLocked },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$TableConst$SingleUserMode.SingleUserModeReadOnly",
      NdbDictionary::Table::/*_enum SingleUserMode_*/SingleUserModeReadOnly },
    { "com.mysql.ndbjtie.ndbapi.NdbDictionary$TableConst$SingleUserMode.SingleUserModeReadWrite",
      NdbDictionary::Table::/*_enum SingleUserMode_*/SingleUserModeReadWrite },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.NoError",
      NdbError::/*_enum Classification_*/NoError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.ApplicationError",
      NdbError::/*_enum Classification_*/ApplicationError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.NoDataFound",
      NdbError::/*_enum Classification_*/NoDataFound },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.ConstraintViolation",
      NdbError::/*_enum Classification_*/ConstraintViolation },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.SchemaError",
      NdbError::/*_enum Classification_*/SchemaError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.UserDefinedError",
      NdbError::/*_enum Classification_*/UserDefinedError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.InsufficientSpace",
      NdbError::/*_enum Classification_*/InsufficientSpace },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.TemporaryResourceError",
      NdbError::/*_enum Classification_*/TemporaryResourceError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.NodeRecoveryError",
      NdbError::/*_enum Classification_*/NodeRecoveryError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.OverloadError",
      NdbError::/*_enum Classification_*/OverloadError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.TimeoutExpired",
      NdbError::/*_enum Classification_*/TimeoutExpired },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.UnknownResultError",
      NdbError::/*_enum Classification_*/UnknownResultError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.InternalError",
      NdbError::/*_enum Classification_*/InternalError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.FunctionNotImplemented",
      NdbError::/*_enum Classification_*/FunctionNotImplemented },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.UnknownErrorCode",
      NdbError::/*_enum Classification_*/UnknownErrorCode },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.NodeShutdown",
      NdbError::/*_enum Classification_*/NodeShutdown },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.SchemaObjectExists",
      NdbError::/*_enum Classification_*/SchemaObjectExists },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Classification.InternalTemporary",
      NdbError::/*_enum Classification_*/InternalTemporary },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Status.Success",
      NdbError::/*_enum Status_*/Success },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Status.TemporaryError",
      NdbError::/*_enum Status_*/TemporaryError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Status.PermanentError",
      NdbError::/*_enum Status_*/PermanentError },
    { "com.mysql.ndbjtie.ndbapi.NdbErrorConst$Status.UnknownResult",
      NdbError::/*_enum Status_*/UnknownResult },
    { "com.mysql.ndbjtie.ndbapi.NdbEventOperation$State.EO_CREATED",
      NdbEventOperation::/*_enum State_*/EO_CREATED },
    { "com.mysql.ndbjtie.ndbapi.NdbEventOperation$State.EO_EXECUTING",
      NdbEventOperation::/*_enum State_*/EO_EXECUTING },
    { "com.mysql.ndbjtie.ndbapi.NdbEventOperation$State.EO_DROPPED",
      NdbEventOperation::/*_enum State_*/EO_DROPPED },
    { "com.mysql.ndbjtie.ndbapi.NdbEventOperation$State.EO_ERROR",
      NdbEventOperation::/*_enum State_*/EO_ERROR },
    { "com.mysql.ndbjtie.ndbapi.NdbIndexScanOperation$BoundType.BoundLE",
      NdbIndexScanOperation::/*_enum BoundType_*/BoundLE },
    { "com.mysql.ndbjtie.ndbapi.NdbIndexScanOperation$BoundType.BoundLT",
      NdbIndexScanOperation::/*_enum BoundType_*/BoundLT },
    { "com.mysql.ndbjtie.ndbapi.NdbIndexScanOperation$BoundType.BoundGE",
      NdbIndexScanOperation::/*_enum BoundType_*/BoundGE },
    { "com.mysql.ndbjtie.ndbapi.NdbIndexScanOperation$BoundType.BoundGT",
      NdbIndexScanOperation::/*_enum BoundType_*/BoundGT },
    { "com.mysql.ndbjtie.ndbapi.NdbIndexScanOperation$BoundType.BoundEQ",
      NdbIndexScanOperation::/*_enum BoundType_*/BoundEQ },
    { "com.mysql.ndbjtie.ndbapi.NdbIndexScanOperation$NotSpecified.MaxRangeNo",
      NdbIndexScanOperation::/*_enum NotSpecified_*/MaxRangeNo },
    { "com.mysql.ndbjtie.ndbapi.NdbOperation$OperationOptionsConst$Flags.OO_ABORTOPTION",
      NdbOperation::OperationOptions::/*_enum Flags_*/OO_ABORTOPTION },
    { "com.mysql.ndbjtie.ndbapi.NdbOperation$OperationOptionsConst$Flags.OO_GETVALUE",
      NdbOperation::OperationOptions::/*_enum Flags_*/OO_GETVALUE },
    { "com.mysql.ndbjtie.ndbapi.NdbOperation$OperationOptionsConst$Flags.OO_SETVALUE",
      NdbOperation::OperationOptions::/*_enum Flags_*/OO_SETVALUE },
    { "com.mysql.ndbjtie.ndbapi.NdbOperation$OperationOptionsConst$Flags.OO_PARTITION_ID",
      NdbOperation::OperationOptions::/*_enum Flags_*/OO_PARTITION_ID },
    { "com.mysql.ndbjtie.ndbapi.NdbOperation$OperationOptionsConst$Flags.OO_INTERPRETED",
      NdbOperation::OperationOptions::/*_enum Flags_*/OO_INTERPRETED },
    { "com.mysql.ndbjtie.ndbapi.NdbOperation$OperationOptionsConst$Flags.OO_ANYVALUE",
      NdbOperation::OperationOptions::/*_enum Flags_*/OO_ANYVALUE },
    { "com.mysql.ndbjtie.ndbapi.NdbOperation$OperationOptionsConst$Flags.OO_CUSTOMDATA",
      NdbOperation::OperationOptions::/*_enum Flags_*/OO_CUSTOMDATA },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$AbortOption.DefaultAbortOption",
      NdbOperation::/*_enum AbortOption_*/DefaultAbortOption },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$AbortOption.AbortOnError",
      NdbOperation::/*_enum AbortOption_*/AbortOnError },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$AbortOption.AO_IgnoreError",
      NdbOperation::/*_enum AbortOption_*/AO_IgnoreError },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$LockMode.LM_Read",
      NdbOperation::/*_enum LockMode_*/LM_Read },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$LockMode.LM_Exclusive",
      NdbOperation::/*_enum LockMode_*/LM_Exclusive },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$LockMode.LM_CommittedRead",
      NdbOperation::/*_enum LockMode_*/LM_CommittedRead },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$LockMode.LM_Dirty",
      NdbOperation::/*_enum LockMode_*/LM_Dirty },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$LockMode.LM_SimpleRead",
      NdbOperation::/*_enum LockMode_*/LM_SimpleRead },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$Type.PrimaryKeyAccess",
      NdbOperation::/*_enum Type_*/PrimaryKeyAccess },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$Type.UniqueIndexAccess",
      NdbOperation::/*_enum Type_*/UniqueIndexAccess },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$Type.TableScan",
      NdbOperation::/*_enum Type_*/TableScan },
    { "com.mysql.ndbjtie.ndbapi.NdbOperationConst$Type.OrderedIndexScan",
      NdbOperation::/*_enum Type_*/OrderedIndexScan },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$BinaryCondition.COND_LE",
      NdbScanFilter::/*_enum BinaryCondition_*/COND_LE },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$BinaryCondition.COND_LT",
      NdbScanFilter::/*_enum BinaryCondition_*/COND_LT },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$BinaryCondition.COND_GE",
      NdbScanFilter::/*_enum BinaryCondition_*/COND_GE },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$BinaryCondition.COND_GT",
      NdbScanFilter::/*_enum BinaryCondition_*/COND_GT },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$BinaryCondition.COND_EQ",
      NdbScanFilter::/*_enum BinaryCondition_*/COND_EQ },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$BinaryCondition.COND_NE",
      NdbScanFilter::/*_enum BinaryCondition_*/COND_NE },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$BinaryCondition.COND_LIKE",
      NdbScanFilter::/*_enum BinaryCondition_*/COND_LIKE },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$BinaryCondition.COND_NOT_LIKE",
      NdbScanFilter::/*_enum BinaryCondition_*/COND_NOT_LIKE },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$Error.FilterTooLarge",
      NdbScanFilter::/*_enum Error_*/FilterTooLarge },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$Group.AND",
      NdbScanFilter::/*_enum Group_*/AND },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$Group.OR",
      NdbScanFilter::/*_enum Group_*/OR },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$Group.NAND",
      NdbScanFilter::/*_enum Group_*/NAND },
    { "com.mysql.ndbjtie.ndbapi.NdbScanFilter$Group.NOR",
      NdbScanFilter::/*_enum Group_*/NOR },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanFlag.SF_TupScan",
      NdbScanOperation::/*_enum ScanFlag_*/SF_TupScan },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanFlag.SF_DiskScan",
      NdbScanOperation::/*_enum ScanFlag_*/SF_DiskScan },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanFlag.SF_OrderBy",
      NdbScanOperation::/*_enum ScanFlag_*/SF_OrderBy },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanFlag.SF_Descending",
      NdbScanOperation::/*_enum ScanFlag_*/SF_Descending },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanFlag.SF_ReadRangeNo",
      NdbScanOperation::/*_enum ScanFlag_*/SF_ReadRangeNo },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanFlag.SF_MultiRange",
      NdbScanOperation::/*_enum ScanFlag_*/SF_MultiRange },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanFlag.SF_KeyInfo",
      NdbScanOperation::/*_enum ScanFlag_*/SF_KeyInfo },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanOptionsConst$Type.SO_SCANFLAGS",
      NdbScanOperation::ScanOptions::/*_enum Type_*/SO_SCANFLAGS },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanOptionsConst$Type.SO_PARALLEL",
      NdbScanOperation::ScanOptions::/*_enum Type_*/SO_PARALLEL },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanOptionsConst$Type.SO_BATCH",
      NdbScanOperation::ScanOptions::/*_enum Type_*/SO_BATCH },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanOptionsConst$Type.SO_GETVALUE",
      NdbScanOperation::ScanOptions::/*_enum Type_*/SO_GETVALUE },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanOptionsConst$Type.SO_PARTITION_ID",
      NdbScanOperation::ScanOptions::/*_enum Type_*/SO_PARTITION_ID },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanOptionsConst$Type.SO_INTERPRETED",
      NdbScanOperation::ScanOptions::/*_enum Type_*/SO_INTERPRETED },
    { "com.mysql.ndbjtie.ndbapi.NdbScanOperation$ScanOptionsConst$Type.SO_CUSTOMDATA",
      NdbScanOperation::ScanOptions::/*_enum Type_*/SO_CUSTOMDATA },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$CommitStatusType.NotStarted",
      NdbTransaction::/*_enum CommitStatusType_*/NotStarted },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$CommitStatusType.Started",
      NdbTransaction::/*_enum CommitStatusType_*/Started },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$CommitStatusType.Committed",
      NdbTransaction::/*_enum CommitStatusType_*/Committed },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$CommitStatusType.Aborted",
      NdbTransaction::/*_enum CommitStatusType_*/Aborted },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$CommitStatusType.NeedAbort",
      NdbTransaction::/*_enum CommitStatusType_*/NeedAbort },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$ExecType.NoExecTypeDef",
      NdbTransaction::/*_enum ExecType_*/NoExecTypeDef },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$ExecType.Prepare",
      NdbTransaction::/*_enum ExecType_*/Prepare },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$ExecType.NoCommit",
      NdbTransaction::/*_enum ExecType_*/NoCommit },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$ExecType.Commit",
      NdbTransaction::/*_enum ExecType_*/Commit },
    { "com.mysql.ndbjtie.ndbapi.NdbTransaction$ExecType.Rollback",
      NdbTransaction::/*_enum ExecType_*/Rollback },
    { "", UNKNOWN_CONSTANT } // last entry
};

long long nativeConstValue(const char * p0) {
    assert(p0);
    const int n = sizeof(constants) / sizeof(constants[0]);
    for (int i = 0; i < n; i++) {
        if (!strcmp(constants[i].name, p0))
            return constants[i].value;
    }
    return UNKNOWN_CONSTANT;
}
