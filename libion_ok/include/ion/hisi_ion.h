/*
 * hisi_ion.h
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


#ifndef _HISI_ION_H
#define _HISI_ION_H


//enum ION_HISI_CUSTOM_CMD {
//	ION_HISI_CUTOM_PHYS,
//};

//Struct used to get phys address of contig heap
struct ion_phys_data {
	int fd_buffer;
	unsigned int size;
	union {
		unsigned int phys;
		unsigned int phys_l;
	      };
	unsigned int phys_h;
};

/**
 * struct ion_map_iommu_data - metadata passed between userspace for iommu mapping
 * @handle:	the handle of buffer
 * @format:	the format of iommu mapping
 *
 * Provided by userspace as an argument to the ioctl
 */

/* metadata for iommu mapping */
struct iommu_map_format {
	unsigned long iova_start;
	unsigned long iova_size;
	unsigned long iommu_ptb_base;
	unsigned long iommu_iova_base;
	unsigned long phys_page_line;
	unsigned long virt_page_line;
	unsigned long is_tile;
};

struct iommu_map_format;
struct ion_map_iommu_data {
	ion_user_handle_t handle;
	struct iommu_map_format format;
};
__BEGIN_DECLS
int ion_map_iommu_ok(int fd, unsigned int handle, struct iommu_map_format format);

int ion_unmap_iommu_ok(int fd, unsigned int handle, struct iommu_map_format format);

int ion_invalidate_fd_ok(int fd, unsigned int handle);
__END_DECLS
/**
 * DOC: ION_IOC_MAP_IOMMU - map a buffr to iova
 */
#define ION_IOC_MAP_IOMMU	_IOWR(ION_IOC_MAGIC, 8, struct ion_map_iommu_data)

/**
 * DOC: ION_IOC_UNMAP_IOMMU - destory iommu mapping of a buffer
 */
#define ION_IOC_UNMAP_IOMMU	_IOWR(ION_IOC_MAGIC, 9, struct ion_map_iommu_data)

/**
 * DOC: ION_IOC_INV - invalidate a shared file descriptors in cache
 */
#define ION_IOC_INV 		_IOWR(ION_IOC_MAGIC, 10, struct ion_fd_data)

#endif
