
int dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		// ����Ʈ�� �����ϰ� �ش� ����Ʈ�� �湮���� ����
		if (nextR >= 0 && nextC >= 0 && nextC < N && nextR < N && !visited[nextR][nextC] && apartments[nextR][nextC] == 1) {
			// �湮 ó��
			visited[nextR][nextC] = 1;
			// ����Ʈ ���� �߰�
			cnt++;
			dfs(nextR, nextC);
		}
	}
	return 0;
}