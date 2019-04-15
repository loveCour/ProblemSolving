
int dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		// 아파트가 존재하고 해당 아파트에 방문하지 않음
		if (nextR >= 0 && nextC >= 0 && nextC < N && nextR < N && !visited[nextR][nextC] && apartments[nextR][nextC] == 1) {
			// 방문 처리
			visited[nextR][nextC] = 1;
			// 아파트 갯수 추가
			cnt++;
			dfs(nextR, nextC);
		}
	}
	return 0;
}