/*
 * Copyright (c) 2015 ARM Limited. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __SECURITY_H__
#define __SECURITY_H__
 
#include <inttypes.h>
 
#define MBED_DOMAIN "4889bada-5a55-46dc-9c26-20a12c588291"
#define MBED_ENDPOINT_NAME "32bb8cb5-64a3-4296-bc92-0bd77701b59b"
 
const uint8_t SERVER_CERT[] = "-----BEGIN CERTIFICATE-----\r\n"
"MIIBmDCCAT6gAwIBAgIEVUCA0jAKBggqhkjOPQQDAjBLMQswCQYDVQQGEwJGSTEN\r\n"
"MAsGA1UEBwwET3VsdTEMMAoGA1UECgwDQVJNMQwwCgYDVQQLDANJb1QxETAPBgNV\r\n"
"BAMMCEFSTSBtYmVkMB4XDTE1MDQyOTA2NTc0OFoXDTE4MDQyOTA2NTc0OFowSzEL\r\n"
"MAkGA1UEBhMCRkkxDTALBgNVBAcMBE91bHUxDDAKBgNVBAoMA0FSTTEMMAoGA1UE\r\n"
"CwwDSW9UMREwDwYDVQQDDAhBUk0gbWJlZDBZMBMGByqGSM49AgEGCCqGSM49AwEH\r\n"
"A0IABLuAyLSk0mA3awgFR5mw2RHth47tRUO44q/RdzFZnLsAsd18Esxd5LCpcT9w\r\n"
"0tvNfBv4xJxGw0wcYrPDDb8/rjujEDAOMAwGA1UdEwQFMAMBAf8wCgYIKoZIzj0E\r\n"
"AwIDSAAwRQIhAPAonEAkwixlJiyYRQQWpXtkMZax+VlEiS201BG0PpAzAiBh2RsD\r\n"
"NxLKWwf4O7D6JasGBYf9+ZLwl0iaRjTjytO+Kw==\r\n"
"-----END CERTIFICATE-----\r\n";
 
const uint8_t CERT[] = "-----BEGIN CERTIFICATE-----\r\n"
"MIIBzzCCAXOgAwIBAgIEbCtooTAMBggqhkjOPQQDAgUAMDkxCzAJBgNVBAYTAkZ\r\n"
"JMQwwCgYDVQQKDANBUk0xHDAaBgNVBAMME21iZWQtY29ubmVjdG9yLTIwMTYwHh\r\n"
"cNMTYxMTA3MTA1MjEzWhcNMTYxMjMxMDYwMDAwWjCBoTFSMFAGA1UEAxNJNDg4O\r\n"
"WJhZGEtNWE1NS00NmRjLTljMjYtMjBhMTJjNTg4MjkxLzMyYmI4Y2I1LTY0YTMt\r\n"
"NDI5Ni1iYzkyLTBiZDc3NzAxYjU5YjEMMAoGA1UECxMDQVJNMRIwEAYDVQQKEwl\r\n"
"tYmVkIHVzZXIxDTALBgNVBAcTBE91bHUxDTALBgNVBAgTBE91bHUxCzAJBgNVBA\r\n"
"YTAkZJMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEzFycgHFzSIdl+rEx+WMvU\r\n"
"qP7IpbIozRfq/ZA6aDnemHO4/VXcf3dHb+1mNNcHiice2W7GhEJZM6DsgQHwwLY\r\n"
"QzAMBggqhkjOPQQDAgUAA0gAMEUCIQCQJsGHFfHEjf53NDf3DoOk6K8guLiEHg4\r\n"
"YWTPa4XugqgIgKfFC+WeNgxBomO8RbjiMtFQWoLYFmMaexRUKbNlBIfg=\r\n"
"-----END CERTIFICATE-----\r\n";
 
const uint8_t KEY[] = "-----BEGIN PRIVATE KEY-----\r\n"
"MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgBKPHr+7pTiDkNq0h\r\n"
"kjCX+HnxxYJ/XSjQ9PV5EIlvIGihRANCAATMXJyAcXNIh2X6sTH5Yy9So/silsij\r\n"
"NF+r9kDpoOd6Yc7j9Vdx/d0dv7WY01weKJx7ZbsaEQlkzoOyBAfDAthD\r\n"
"-----END PRIVATE KEY-----\r\n";
 
#endif //__SECURITY_H__
