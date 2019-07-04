#include "net_adapter_infos.hpp"

AdapterInfo primary_adapter() {
    pNetAdapterInfo* Adapters = new_pNetAdapterInfo();							// Get adapters //
	
    AdapterInfo info;
	const NetAdapterInfo* Current = get_primary_pNetAdapterInfo( Adapters );	// Get primary adapter //

    if ( Current ) {
            info.name = std::string(Current->Name); 
            info.ip = std::string(Current->IP); 
            info.netmask = std::string(Current->NetMask); 
            info.broadcast = std::string(Current->Broadcast); 
            info.mac = std::string(Current->MAC); 
    }
    else {
        printf( "No Primary Adapter Found!\n" );
    }

	delete_pNetAdapterInfo( Adapters );											// Clean up //

    return info;
}


std::map<std::string, AdapterInfo> all_adapter() {
	pNetAdapterInfo* Adapters = new_pNetAdapterInfo();
    std::map<std::string, AdapterInfo> infos;

	size_t AdapterCount = count_pNetAdapterInfo(Adapters);
	for ( size_t Index = 0; Index < AdapterCount; Index++ ) {
        const NetAdapterInfo* Current = get_pNetAdapterInfo( Adapters, Index );	// get_, not get_primary_ //
        AdapterInfo info;
        info.name = std::string(Current->Name); 
        info.ip = std::string(Current->IP); 
        info.netmask = std::string(Current->NetMask); 
        info.broadcast = std::string(Current->Broadcast); 
        info.mac = std::string(Current->MAC); 

        infos.emplace(info.mac, info);
	}

	delete_pNetAdapterInfo( Adapters );
    return infos;
}