/*
 * hisi_ion.c
 *
 * Reversed ION functions compatible with Hisilicon Kirin SoCs
 *
 *   Copyright 2017 OpenKirin
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#define LOG_TAG "OpenKirin_ION"

#include <cutils/log.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/ion.h>
#include <ion/hisi_ion.h>

int ion_map_iommu_ok(int fd, unsigned int handle,
		struct iommu_map_format format)
{
	struct ion_map_iommu_data data;
	data.handle = handle;
	data.format = format;

	int ret = ioctl(fd, ION_IOC_MAP_IOMMU, &data);
	
	if (ret)
	    ALOGE("ION_MAP_IOMMU: Failed with code:%d %s\n", ret, strerror(errno));

	return ret;
}

int ion_unmap_iommu_ok(int fd, unsigned int handle,
		    struct iommu_map_format format)
{
	struct ion_map_iommu_data data;
	data.handle = handle;
	data.format = format;

	int ret = ioctl(fd, ION_IOC_UNMAP_IOMMU, &data);

	if (ret)
	    ALOGE("ION_UNMAP_IOMMU: Failed with code:%d %s\n", ret, strerror(errno));

	return ret;
}

int ion_invalidate_fd_ok(int fd, unsigned int handle)
{
	struct ion_fd_data data;
	data.fd = handle;

	int ret = ioctl(fd, ION_IOC_INV, &data);

	if (ret)
	    ALOGE("ION_INVALIDATE_FD: Failed with code: %d %s\n", ret, strerror(errno));

	return ret;
}
