/* soapClient.cpp
   Generated by gSOAP 2.8.32 for add.h

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.8.32 2016-07-07 06:17:58 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__Syndwsadata(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct SyndwsadataRequest request, struct SyndwsadataResponse *serviceResponse)
{	struct ns__Syndwsadata soap_tmp_ns__Syndwsadata;
	struct ns__SyndwsadataResponse *soap_tmp_ns__SyndwsadataResponse;
	soap_tmp_ns__Syndwsadata.request = request;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize_ns__Syndwsadata(soap, &soap_tmp_ns__Syndwsadata);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__Syndwsadata(soap, &soap_tmp_ns__Syndwsadata, "ns:Syndwsadata", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__Syndwsadata(soap, &soap_tmp_ns__Syndwsadata, "ns:Syndwsadata", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!serviceResponse)
		return soap_closesock(soap);
	soap_default_SyndwsadataResponse(soap, serviceResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__SyndwsadataResponse = soap_get_ns__SyndwsadataResponse(soap, NULL, "ns:SyndwsadataResponse", NULL);
	if (!soap_tmp_ns__SyndwsadataResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (serviceResponse && soap_tmp_ns__SyndwsadataResponse->serviceResponse)
		*serviceResponse = *soap_tmp_ns__SyndwsadataResponse->serviceResponse;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__syndwsaTicketInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct SyndwsaTicketInfoRequest request, struct SyndwsaTicketInfoResponse *serviceResponse)
{	struct ns__syndwsaTicketInfo soap_tmp_ns__syndwsaTicketInfo;
	struct ns__syndwsaTicketInfoResponse *soap_tmp_ns__syndwsaTicketInfoResponse;
	soap_tmp_ns__syndwsaTicketInfo.request = request;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize_ns__syndwsaTicketInfo(soap, &soap_tmp_ns__syndwsaTicketInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__syndwsaTicketInfo(soap, &soap_tmp_ns__syndwsaTicketInfo, "ns:syndwsaTicketInfo", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__syndwsaTicketInfo(soap, &soap_tmp_ns__syndwsaTicketInfo, "ns:syndwsaTicketInfo", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!serviceResponse)
		return soap_closesock(soap);
	soap_default_SyndwsaTicketInfoResponse(soap, serviceResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__syndwsaTicketInfoResponse = soap_get_ns__syndwsaTicketInfoResponse(soap, NULL, "ns:syndwsaTicketInfoResponse", NULL);
	if (!soap_tmp_ns__syndwsaTicketInfoResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (serviceResponse && soap_tmp_ns__syndwsaTicketInfoResponse->serviceResponse)
		*serviceResponse = *soap_tmp_ns__syndwsaTicketInfoResponse->serviceResponse;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */
