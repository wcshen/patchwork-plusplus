import open3d as o3d
import numpy as np
import os


def read_pcd(pcd_file):
    pcd = o3d.io.read_point_cloud(pcd_file)
    points = np.asarray(pcd.points)
    points_num = points.shape[0]
    zeros = np.zeros(shape=(points_num, 1))
    points = np.concatenate([points, zeros], axis=-1)
    return points

pcds_dir = '/home/swc/Plus/datasets/unknown/pcds/'
bins_dir = '/home/swc/Plus/datasets/unknown/bins/'
pcds_names = os.listdir(pcds_dir)
for pcds_name in pcds_names:
    pcd_path = pcds_dir + pcds_name
    bin_path = bins_dir + pcds_name
    points = read_pcd(pcd_path)
    with open(bin_path, 'wb') as f:
        points.tofile(f)