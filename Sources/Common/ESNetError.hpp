/* See: https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2 */

#pragma once

#include <array>
#include <algorithm>
#include <string_view>

namespace ESNet {
	enum class ESNetError : u32 {
		UnknownEnum = 0,
		InvalidHandle = 6,
		Memory = 8,
		InvalidParameter = 87,
		OperationAborted = 995,
		IOIncomplete = 996,
		IOPending = 997,
		Interrupted = 10004,
		InvalidFileHandle = 10009,
		AccessDenied = 10013,
		BadAddress = 10014,
		InvalidArgument = 10022,
		MaxOpenSockets = 10024,
		WouldBlock = 10035,
		NowInProgress = 10036,
		AlreadyInProgress = 10037,
		NotSocket = 10038,
		DestinationRequired = 10039,
		MessageTooLong = 10040,
		ProtocolType = 10041,
		ProtocolOption = 10042,
		ProtocolSupport = 10043,
		SocketSupport = 10044,
		OperationSupport = 10045,
		ProtocolFamily = 10046,
		AddressFamily = 10047,
		AddressInUse = 10048,
		AddressUnavailable = 10049,
		NetworkDown = 10050,
		NetworkUnreachable = 10051,
		NetworkReset = 10052,
		Abort = 10053,
		Reset = 10054,
		BufferSpace = 10055,
		AlreadyConnected = 10056,
		NotConnected = 10057,
		SocketShutdown = 10058,
		References = 10059,
		TimedOut = 10060,
		ConnectionRefused = 10061,
		NameTranslation = 10062,
		NameTooLong = 10063,
		HostDown = 10064,
		HostUnreachable = 10065,
		DirectoryNotEmpty = 10066,
		MaxProcesses = 10067,
		UserQuota = 10068,
		DiskQuota = 10069,
		FileHandlerStale = 10070,
		Remote = 10071,
		SystemNotReady = 10091,
		VersionUnsupported = 10092,
		NotInitialized = 10093,
		GracefulDisconnect = 10101,
		NoMore = 10102,
		Canceled = 10103,
		InvalidProcedureTable = 10104,
		InvalidProvider = 10105,
		ProviderFailedInitialization = 10106,
		SystemCallFailure = 10107,
		ServiceNotFound = 10108,
		TypeNotFound = 10109,
		NoMore_ = 10110,
		Canceled_ = 10111,
		QueryRefused = 10112,
		HostNotFound = 11001,
		TryAgain = 11002,
		NoRecovery = 11003,
		NoData = 11004,
		QoSReceivers = 11005,
		QoSSenders = 11006,
		QoSNoSenders = 11007,
		QoSNoReceivers = 11008,
		QoSRequestConfirmed = 11009,
		QoSAdmissionFailure = 11010,
		QoSPolicyFailure = 11011,
		QoSBadStyle = 11012,
		QoSBadObject = 11013,
		QoSTrafficControl = 11014,
		QoSGeneric = 11015,
		QoSServiceType = 11016,
		QoSFlowSpec = 11017,
		QoSProviderBuffer = 11018,
		QoSFilterStyle = 11019,
		QoSFilterType = 11020,
		QoSFilterCount = 11021,
		QoSObjectLength = 11022,
		QoSFlowCount = 11023,
		QoSUnknownObject = 11024,
		QoSPolicyObject = 11025,
		QoSFlowDescriptor = 11026,
		QosFlowspec = 11027,
		QoSFilterspec = 11028,
		QoSShapeDiscardMode = 11029,
		QoSShapingRateObject = 11030,
		QoSReservedPolicyElementType = 11031,
		Success = 0xFFFFFFFF
	};
	struct ESNetEnumEntry {
		ESNetError const error;
		std::string_view const name;
		std::string_view const description;
	};
	inline constexpr std::array<ESNetEnumEntry, 96> ESNET_ERROR_ENUMS{
		ESNetEnumEntry{
			.error = ESNetError::UnknownEnum,
			.name = "UnknownEnum",
			.description = "Enum integral value is unknown."
		}, 
		ESNetEnumEntry{
			.error = ESNetError::InvalidHandle,
			.name = "InvalidHandle",
			.description = "Specified event object handle is invalid. An application attempts to use an event object, but the specified handle is not valid."
		},
		ESNetEnumEntry{
			.error = ESNetError::Memory,
			.name = "Memory",
			.description = "Insufficient memory available. An application used a Windows Sockets function that directly maps to a Windows function. The Windows function is indicating a lack of required memory resources."
		},
		ESNetEnumEntry{
			.error = ESNetError::InvalidParameter,
			.name = "InvalidParameter",
			.description = "One or more parameters are invalid. An application used a Windows Sockets function which directly maps to a Windows function. The Windows function is indicating a problem with one or more parameters."
		},
		ESNetEnumEntry{
			.error = ESNetError::OperationAborted,
			.name = "OperationAborted",
			.description = "Overlapped operation aborted. An overlapped operation was canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in WSAIoctl."
		},
		ESNetEnumEntry{
			.error = ESNetError::IOIncomplete,
			.name = "IOIncomplete",
			.description = "Overlapped I/O event object not in signaled state. The application has tried to determine the status of an overlapped operation which is not yet completed.Applications that use WSAGetOverlappedResult(with the fWait flag set to FALSE) in a polling mode to determine when an overlapped operation has completed, get this error code until the operation is complete."
		},
		ESNetEnumEntry{
			.error = ESNetError::IOPending,
			.name = "IOPending",
			.description = "Overlapped operations will complete later. The application has initiated an overlapped operation that cannot be completed immediately.A completion indication will be given later when the operation has been completed."
		},
		ESNetEnumEntry{
			.error = ESNetError::Interrupted,
			.name = "Interrupted",
			.description = "Interrupted function call. A blocking operation was interrupted by a call to WSACancelBlockingCall."
		},
		ESNetEnumEntry{
			.error = ESNetError::InvalidFileHandle,
			.name = "InvalidFileHandle",
			.description = "File handle is not valid. The file handle supplied is not valid."
		},
		ESNetEnumEntry{
			.error = ESNetError::AccessDenied,
			.name = "AccessDenied",
			.description = "Permission denied. An attempt was made to access a socket in a way forbidden by its access permissions.An example is using a broadcast address for sendto without broadcast permission being set using setsockopt(SO_BROADCAST). Another possible reason for the WSAEACCES error is that when the bind function is called(on Windows NT 4.0 with SP4 and later), another application, service, or kernel mode driver is bound to the same address with exclusive access.Such exclusive access is a new feature of Windows NT 4.0 with SP4 and later, and is implemented by using the SO_EXCLUSIVEADDRUSE option."
		},
		ESNetEnumEntry{
			.error = ESNetError::BadAddress,
			.name = "BadAddress",
			.description = "Bad address. The system detected an invalid pointer address in attempting to use a pointer argument of a call.This error occurs if an application passes an invalid pointer value, or if the length of the buffer is too small.For instance, if the length of an argument, which is a sockaddr structure, is smaller than the sizeof(sockaddr)."
		},
		ESNetEnumEntry{
			.error = ESNetError::InvalidArgument,
			.name = "InvalidArgument",
			.description = "Invalid argument. Some invalid argument was supplied(for example, specifying an invalid level to the setsockopt function).In some instances, it also refers to the current state of the socket—for instance, calling accept on a socket that is not listening."
		},
		ESNetEnumEntry{
			.error = ESNetError::MaxOpenSockets,
			.name = "MaxOpenSockets",
			.description = "Too many open files. Too many open sockets.Each implementation may have a maximum number of socket handles available, either globally, per process, or per thread."
		},
		ESNetEnumEntry{
			.error = ESNetError::WouldBlock,
			.name = "WouldBlock",
			.description = "Resource temporarily unavailable. This error is returned from operations on nonblocking sockets that cannot be completed immediately, for example recv when no data is queued to be read from the socket.It is a nonfatal error, and the operation should be retried later.It is normal for WSAEWOULDBLOCK to be reported as the result from calling connect on a nonblocking SOCK_STREAM socket, since some time must elapse for the connection to be established."
		},
		ESNetEnumEntry{
			.error = ESNetError::NowInProgress,
			.name = "NowInProgress",
			.description = "Operation now in progress. A blocking operation is currently executing.Windows Sockets only allows a single blocking operation—per - task or thread—to be outstanding, and if any other function call is made(whether or not it references that or any other socket) the function fails with the WSAEINPROGRESS error."
		},
		ESNetEnumEntry{
			.error = ESNetError::AlreadyInProgress,
			.name = "AlreadyInProgress",
			.description = "Operation already in progress. An operation was attempted on a nonblocking socket with an operation already in progress—that is, calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request(WSAAsyncGetXbyY) that has already been canceled or completed."
		},
		ESNetEnumEntry{
			.error = ESNetError::NotSocket,
			.name = "NotSocket",
			.description = "Socket operation on nonsocket. An operation was attempted on something that is not a socket.Either the socket handle parameter did not reference a valid socket, or for select, a member of an fd_set was not valid."
		},
		ESNetEnumEntry{
			.error = ESNetError::DestinationRequired,
			.name = "DestinationRequired",
			.description = "Destination address required. A required address was omitted from an operation on a socket.For example, this error is returned if sendto is called with the remote address of ADDR_ANY."
		},
		ESNetEnumEntry{
			.error = ESNetError::MessageTooLong,
			.name = "MessageTooLong",
			.description = "Message too long. A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself."
		},
		ESNetEnumEntry{
			.error = ESNetError::ProtocolType,
			.name = "ProtocolType",
			.description = "Protocol wrong type for socket. A protocol was specified in the socket function call that does not support the semantics of the socket type requested.For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM."
		},
		ESNetEnumEntry{
			.error = ESNetError::ProtocolOption,
			.name = "ProtocolOption",
			.description = "Bad protocol option. An unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call."
		},
		ESNetEnumEntry{
			.error = ESNetError::ProtocolSupport,
			.name = "ProtocolSupport",
			.description = "Protocol not supported. The requested protocol has not been configured into the system, or no implementation for it exists.For example, a socket call requests a SOCK_DGRAM socket, but specifies a stream protocol."
		},
		ESNetEnumEntry{
			.error = ESNetError::SocketSupport,
			.name = "SocketSupport",
			.description = "Socket type not supported. The support for the specified socket type does not exist in this address family.For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all."
		},
		ESNetEnumEntry{
			.error = ESNetError::OperationSupport,
			.name = "OperationSupport",
			.description = "Operation not supported. The attempted operation is not supported for the type of object referenced.Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket."
		},
		ESNetEnumEntry{
			.error = ESNetError::ProtocolFamily,
			.name = "ProtocolFamily",
			.description = "Protocol family not supported. The protocol family has not been configured into the system or no implementation for it exists.This message has a slightly different meaning from WSAEAFNOSUPPORT.However, it is interchangeable in most cases, and all Windows Sockets functions that return one of these messages also specify WSAEAFNOSUPPORT."
		},
		ESNetEnumEntry{
			.error = ESNetError::AddressFamily,
			.name = "AddressFamily",
			.description = "Address family not supported by protocol family. An address incompatible with the requested protocol was used.All sockets are created with an associated address family(that is, AF_INET for Internet Protocols) and a generic protocol type(that is, SOCK_STREAM).This error is returned if an incorrect protocol is explicitly requested in the socket call, or if an address of the wrong family is used for a socket, for example, in sendto."
		},
		ESNetEnumEntry{
			.error = ESNetError::AddressInUse,
			.name = "AddressInUse",
			.description = "Address already in use. Typically, only one usage of each socket address(protocol / IP address / port) is permitted.This error occurs if an application attempts to bind a socket to an IP address / port that has already been used for an existing socket, or a socket that was not closed properly, or one that is still in the process of closing.For server applications that need to bind multiple sockets to the same port number, consider using setsockopt(SO_REUSEADDR).Client applications usually need not call bind at all—connect chooses an unused port automatically.When bind is called with a wildcard address(involving ADDR_ANY), a WSAEADDRINUSE error could be delayed until the specific address is committed.This could happen with a call to another function later, including connect, listen, WSAConnect, or WSAJoinLeaf."
		},
		ESNetEnumEntry{
			.error = ESNetError::AddressUnavailable,
			.name = "AddressUnavailable",
			.description = "Cannot assign requested address. The requested address is not valid in its context.This normally results from an attempt to bind to an address that is not valid for the local computer.This can also result from connect, sendto, WSAConnect, WSAJoinLeaf, or WSASendTo when the remote address or port is not valid for a remote computer(for example, address or port 0)."
		},
		ESNetEnumEntry{
			.error = ESNetError::NetworkDown,
			.name = "NetworkDown ",
			.description = "Network is down. A socket operation encountered a dead network.This could indicate a serious failure of the network system(that is, the protocol stack that the Windows Sockets DLL runs over), the network interface, or the local network itself."
		},
		ESNetEnumEntry{
			.error = ESNetError::NetworkUnreachable,
			.name = "NetworkUnreachable",
			.description = "Network is unreachable. A socket operation was attempted to an unreachable network.This usually means the local software knows no route to reach the remote host."
		},
		ESNetEnumEntry{
			.error = ESNetError::NetworkReset,
			.name = "NetworkReset",
			.description = "Network dropped connection on reset. The connection has been broken due to keep - alive activity detecting a failure while the operation was in progress.It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed."
		},
		ESNetEnumEntry{
			.error = ESNetError::Abort,
			.name = "Abort",
			.description = "Software caused connection abort. An established connection was aborted by the software in your host computer, possibly due to a data transmission time - out or protocol error."
		},
		ESNetEnumEntry{
			.error = ESNetError::Reset,
			.name = "Reset",
			.description = "Connection reset by peer. An existing connection was forcibly closed by the remote host.This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, the host or remote network interface is disabled, or the remote host uses a hard close(see setsockopt for more information on the SO_LINGER option on the remote socket).This error may also result if a connection was broken due to keep - alive activity detecting a failure while one or more operations are in progress.Operations that were in progress fail with WSAENETRESET.Subsequent operations fail with WSAECONNRESET."
		},
		ESNetEnumEntry{
			.error = ESNetError::BufferSpace,
			.name = "BufferSpace",
			.description = "No buffer space available. An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full."
		},
		ESNetEnumEntry{
			.error = ESNetError::AlreadyConnected,
			.name = "AlreadyConnected",
			.description = "Socket is already connected. A connect request was made on an already - connected socket.Some implementations also return this error if sendto is called on a connected SOCK_DGRAM socket(for SOCK_STREAM sockets, the to parameter in sendto is ignored) although other implementations treat this as a legal occurrence."
		},
		ESNetEnumEntry{
			.error = ESNetError::NotConnected,
			.name = "NotConnected",
			.description = "Socket is not connected. A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using sendto) no address was supplied.Any other type of operation might also return this error—for example, setsockopt setting SO_KEEPALIVE if the connection has been reset."
		},
		ESNetEnumEntry{
			.error = ESNetError::SocketShutdown,
			.name = "SocketShutdown",
			.description = "Cannot send after socket shutdown. A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call.By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, or both have been discontinued."
		},
		ESNetEnumEntry{
			.error = ESNetError::References,
			.name = "References",
			.description = "Too many references. Too many references to some kernel object."
		},
		ESNetEnumEntry{
			.error = ESNetError::TimedOut,
			.name = "TimedOut",
			.description = "Connection timed out. A connection attempt failed because the connected party did not properly respond after a period of time, or the established connection failed because the connected host has failed to respond."
		},
		ESNetEnumEntry{
			.error = ESNetError::ConnectionRefused,
			.name = "ConnectionRefused",
			.description = "Connection refused. No connection could be made because the target computer actively refused it.This usually results from trying to connect to a service that is inactive on the foreign host—that is, one with no server application running."
		},
		ESNetEnumEntry{
			.error = ESNetError::NameTranslation,
			.name = "NameTranslation",
			.description = "Cannot translate name. Cannot translate a name."
		},
		ESNetEnumEntry{
			.error = ESNetError::NameTooLong,
			.name = "NameTooLong",
			.description = "Name too long. A name component or a name was too long."
		},
		ESNetEnumEntry{
			.error = ESNetError::HostDown,
			.name = "HostDown",
			.description = "Host is down. A socket operation failed because the destination host is down.A socket operation encountered a dead host.Networking activity on the local host has not been initiated.These conditions are more likely to be indicated by the error WSAETIMEDOUT."
		},
		ESNetEnumEntry{
			.error = ESNetError::HostUnreachable,
			.name = "HostUnreachable",
			.description = "No route to host. A socket operation was attempted to an unreachable host. See WSAENETUNREACH."
		},
		ESNetEnumEntry{
			.error = ESNetError::DirectoryNotEmpty,
			.name = "DirectoryNotEmpty",
			.description = "Directory not empty. Cannot remove a directory that is not empty."
		},
		ESNetEnumEntry{
			.error = ESNetError::MaxProcesses,
			.name = "MaxProcesses",
			.description = "Too many processes. A Windows Sockets implementation may have a limit on the number of applications that can use it simultaneously. WSAStartup may fail with this error if the limit has been reached."
		},
		ESNetEnumEntry{
			.error = ESNetError::UserQuota,
			.name = "UserQuota",
			.description = "User quota exceeded. Ran out of user quota."
		},
		ESNetEnumEntry{
			.error = ESNetError::DiskQuota,
			.name = "DiskQuota",
			.description = "Disk quota exceeded. Ran out of disk quota."
		},
		ESNetEnumEntry{
			.error = ESNetError::FileHandlerStale,
			.name = "FileHandlerStale",
			.description = "Stale file handle reference. The file handle reference is no longer available."
		},
		ESNetEnumEntry{
			.error = ESNetError::Remote,
			.name = "Remote",
			.description = "Item is remote. The item is not available locally."
		},
		ESNetEnumEntry{
			.error = ESNetError::SystemNotReady,
			.name = "SystemNotReady",
			.description = "Network subsystem is unavailable. This error is returned by WSAStartup if the Windows Sockets implementation cannot function at this time because the underlying system it uses to provide network services is currently unavailable. Users should check:\n- That the appropriate Windows Sockets DLL file is in the current path.\n- That they are not trying to use more than one Windows Sockets implementation simultaneously. If there is more than one Winsock DLL on your system, be sure the first one in the path is appropriate for the network subsystem currently loaded.\n- The Windows Sockets implementation documentation to be sure all necessary components are currently installed and configured correctly."
		},
		ESNetEnumEntry{
			.error = ESNetError::VersionUnsupported,
			.name = "VersionUnsupported",
			.description = "Winsock.dll version out of range. The current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application.Check that no old Windows Sockets DLL files are being accessed."
		},
		ESNetEnumEntry{
			.error = ESNetError::NotInitialized,
			.name = "NotInitialized",
			.description = "Successful WSAStartup not yet performed. Either the application has not called WSAStartup or WSAStartup failed.The application may be accessing a socket that the current active task does not own(that is, trying to share a socket between tasks), or WSACleanup has been called too many times."
		},
		ESNetEnumEntry{
			.error = ESNetError::GracefulDisconnect,
			.name = "GracefulDisconnect",
			.description = "Graceful shutdown in progress. Returned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence."
		},
		ESNetEnumEntry{
			.error = ESNetError::NoMore,
			.name = "NoMore",
			.description = "No more results. No more results can be returned by the WSALookupServiceNext function."
		},
		ESNetEnumEntry{
			.error = ESNetError::Canceled,
			.name = "Canceled",
			.description = "Call has been canceled. A call to the WSALookupServiceEnd function was made while this call was still processing.The call has been canceled."
		},
		ESNetEnumEntry{
			.error = ESNetError::InvalidProcedureTable,
			.name = "InvalidProcedureTable",
			.description = "Procedure call table is invalid. The service provider procedure call table is invalid.A service provider returned a bogus procedure table to Ws2_32.dll.This is usually caused by one or more of the function pointers being NULL."
		},
		ESNetEnumEntry{
			.error = ESNetError::InvalidProvider,
			.name = "InvalidProvider",
			.description = "Service provider is invalid. The requested service provider is invalid.This error is returned by the WSCGetProviderInfo and WSCGetProviderInfo32 functions if the protocol entry specified could not be found.This error is also returned if the service provider returned a version number other than 2.0."
		},
		ESNetEnumEntry{
			.error = ESNetError::ProviderFailedInitialization,
			.name = "ProviderFailedInitialization",
			.description = "Service provider failed to initialize. The requested service provider could not be loaded or initialized.This error is returned if either a service provider's DLL could not be loaded (LoadLibrary failed) or the provider's WSPStartup or NSPStartup function failed."
		},
		ESNetEnumEntry{
			.error = ESNetError::SystemCallFailure,
			.name = "SystemCallFailure",
			.description = "System call failure. A system call that should never fail has failed.This is a generic error code, returned various conditions. Returned when a system call that should never fail does fail.For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to manipulate the protocol / namespace catalogs. Returned when a provider does not return SUCCESS and does not provide an extended error code.Can indicate a service provider implementation error."
		},
		ESNetEnumEntry{
			.error = ESNetError::ServiceNotFound,
			.name = "ServiceNotFound",
			.description = "Service not found. No such service is known.The service cannot be found in the specified name space."
		},
		ESNetEnumEntry{
			.error = ESNetError::TypeNotFound,
			.name = "TypeNotFound",
			.description = "Class type not found. The specified class was not found."
		},
		ESNetEnumEntry{
			.error = ESNetError::NoMore_,
			.name = "NoMore_",
			.description = "No more results. No more results can be returned by the WSALookupServiceNext function."
		},
		ESNetEnumEntry{
			.error = ESNetError::Canceled_,
			.name = "Canceled_",
			.description = "Call was canceled. A call to the WSALookupServiceEnd function was made while this call was still processing.The call has been canceled."
		},
		ESNetEnumEntry{
			.error = ESNetError::QueryRefused,
			.name = "QueryRefused",
			.description = "Database query was refused. A database query failed because it was actively refused."
		},
		ESNetEnumEntry{
			.error = ESNetError::HostNotFound,
			.name = "HostNotFound",
			.description = "Host not found. No such host is known. The name is not an official host name or alias, or it cannot be found in the database(s) being queried. This error may also be returned for protocol and service queries, and means that the specified name could not be found in the relevant database."
		},
		ESNetEnumEntry{
			.error = ESNetError::TryAgain,
			.name = "TryAgain",
			.description = "Nonauthoritative host not found. This is usually a temporary error during host name resolution and means that the local server did not receive a response from an authoritative server.A retry at some time later may be successful."
		},
		ESNetEnumEntry{
			.error = ESNetError::NoRecovery,
			.name = "NoRecovery",
			.description = "This is a nonrecoverable error. This indicates that some sort of nonrecoverable error occurred during a database lookup.This may be because the database files(for example, BSD - compatible HOSTS, SERVICES, or PROTOCOLS files) could not be found, or a DNS request was returned by the server with a severe error."
		},
		ESNetEnumEntry{
			.error = ESNetError::NoData,
			.name = "NoData",
			.description = "Valid name, no data record of requested type. The requested name is valid and was found in the database, but it does not have the correct associated data being resolved for.The usual example for this is a host name - to - address translation attempt(using gethostbyname or WSAAsyncGetHostByName) which uses the DNS(Domain Name Server).An MX record is returned but no A record—indicating the host itself exists, but is not directly reachable."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSReceivers,
			.name = "QoSReceivers",
			.description = "QoS receivers. At least one QoS reserve has arrived."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSSenders,
			.name = "QoSSenders",
			.description = "QoSSenders"
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSNoSenders,
			.name = "QoSNoSenders",
			.description = "No QoS senders. There are no QoS senders."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSNoReceivers,
			.name = "QoSNoReceivers",
			.description = "QoS no receivers. There are no QoS receivers."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSRequestConfirmed,
			.name = "QoSRequestConfirmed",
			.description = "QoS request confirmed. The QoS reserve request has been confirmed."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSAdmissionFailure,
			.name = "QoSAdmissionFailure",
			.description = "QoS admission error. A QoS error occurred due to lack of resources."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSPolicyFailure,
			.name = "QoSPolicyFailure",
			.description = "QoS policy failure. The QoS request was rejected because the policy system couldn't allocate the requested resource within the existing policy."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSBadStyle,
			.name = "QoSBadStyle",
			.description = "QoS bad style. An unknown or conflicting QoS style was encountered."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSBadObject,
			.name = "QoSBadObject",
			.description = "QoS bad object. A problem was encountered with some part of the filterspec or the provider - specific buffer in general."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSTrafficControl,
			.name = "QoSTrafficControl",
			.description = "QoS traffic control error. An error with the underlying traffic control(TC) API as the generic QoS request was converted for local enforcement by the TC API.This could be due to an out of memory error or to an internal QoS provider error."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSGeneric,
			.name = "QoSGeneric",
			.description = "QoS generic error. A general QoS error."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSServiceType,
			.name = "QoSServiceType",
			.description = "QoS service type error. An invalid or unrecognized service type was found in the QoS flowspec."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSFlowSpec,
			.name = "QoSFlowSpec",
			.description = "QoS flowspec error. An invalid or inconsistent flowspec was found in the QOS structure."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSProviderBuffer,
			.name = "QoSProviderBuffer",
			.description = "Invalid QoS provider buffer. An invalid QoS provider - specific buffer."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSFilterStyle,
			.name = "QoSFilterStyle",
			.description = "Invalid QoS filter style. An invalid QoS filter style was used."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSFilterType,
			.name = "QoSFilterType",
			.description = "Incorrect QoS filter count. An incorrect number of QoS FILTERSPECs were specified in the FLOWDESCRIPTOR."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSFilterCount,
			.name = "QoSFilterCount",
			.description = "Incorrect QoS filter count. An incorrect number of QoS FILTERSPECs were specified in the FLOWDESCRIPTOR."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSObjectLength,
			.name = "QoSObjectLength",
			.description = "Invalid QoS object length. An object with an invalid ObjectLength field was specified in the QoS provider - specific buffer."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSFlowCount,
			.name = "QoSFlowCount",
			.description = "Incorrect QoS flow count. An incorrect number of flow descriptors was specified in the QoS structure."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSUnknownObject,
			.name = "QoSUnknownObject",
			.description = "Unrecognized QoS object. An unrecognized object was found in the QoS provider - specific buffer."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSPolicyObject,
			.name = "QoSPolicyObject",
			.description = "Invalid QoS policy object. An invalid policy object was found in the QoS provider - specific buffer."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSFlowDescriptor,
			.name = "QoSFlowDescriptor",
			.description = "Invalid QoS flow descriptor. An invalid QoS flow descriptor was found in the flow descriptor list."
		},
		ESNetEnumEntry{
			.error = ESNetError::QosFlowspec,
			.name = "QosFlowspec",
			.description = "Invalid QoS provider-specific flowspec. An invalid or inconsistent flowspec was found in the QoS provider - specific buffer."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSFilterspec,
			.name = "QoSFilterspec",
			.description = "Invalid QoS provider-specific filterspec. An invalid FILTERSPEC was found in the QoS provider - specific buffer."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSShapeDiscardMode,
			.name = "QoSShapeDiscardMode",
			.description = "Invalid QoS shape discard mode object. An invalid shape discard mode object was found in the QoS provider - specific buffer."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSShapingRateObject,
			.name = "QoSShapingRateObject",
			.description = "Invalid QoS shaping rate object. An invalid shaping rate object was found in the QoS provider - specific buffer."
		},
		ESNetEnumEntry{
			.error = ESNetError::QoSReservedPolicyElementType,
			.name = "QoSReservedPolicyElementType",
			.description = "Reserved policy QoS element type. A reserved policy element was found in the QoS provider - specific buffer."
		}
	};

	inline constexpr ESNetEnumEntry const& getEnumEntry(ESNetError const error) {
		auto const it = std::find_if(std::cbegin(ESNET_ERROR_ENUMS), std::cend(ESNET_ERROR_ENUMS), [&error](auto const entry) { return entry.error == error; });
		return it == std::cend(ESNET_ERROR_ENUMS) ? ESNET_ERROR_ENUMS[0] : *it;
	}
}